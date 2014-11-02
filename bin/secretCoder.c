#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#include "../lib/fileHandling.h"
#include "../lib/messages.h"
#include "../lib/secretCoder.h"
#include "../lib/userInteraction.h"
#include "../lib/files.h"

char * encryptedFileName = "EncryptedMessage.txt";
char * decryptedFileName = "DecryptedMessage.txt";

FileContainer collapseKey(char *keyName) {
	char currentChar;
	FILE* keyFile = fopen(keyName, "r");
	FileContainer tempContainer;
	if (keyFile == NULL) {
		printMessage(TYPE_ERROR, ERROR_INVALID_KEY);
	} else {
		tempContainer.key = malloc(getSize(keyName));
		memset(tempContainer.key, 0, sizeof(tempContainer.key));
		tempContainer.keyCount = 0;

		while (!feof(keyFile) && fscanf(keyFile, "%c", &currentChar) == 1) {
			if (isalpha(currentChar)) {
				if (isupper(currentChar)) {
					currentChar = tolower(currentChar);
				}
				tempContainer.key[tempContainer.keyCount++] = currentChar;
			}
		}
	}
	fclose(keyFile);
	return tempContainer;
}

void writeIntToFile(int number, char *fileName) {
	FILE* encryptedFile = fopen(fileName, "a");
	if (encryptedFile == NULL) {
		printMessage(TYPE_ERROR, ERROR_LOAD_FILE);
	} else {
		fprintf(encryptedFile, "%c", '[');
		fprintf(encryptedFile, "%d", number);
		fprintf(encryptedFile, "%c", ']');
	}
	fclose(encryptedFile);
}

void writeCharToFile(char c, char *fileName) {
	FILE* encryptedFile = fopen(fileName, "a");
	if (encryptedFile == NULL) {
		printMessage(TYPE_ERROR, ERROR_INVALID_KEY);
	} else {
		fprintf(encryptedFile, "%c", c);
	}
	fclose(encryptedFile);
}

void encodeFile (FileContainer files, char * msgName, int d) {

	IndexHolder iHolder;
	FILE* msgFile = fopen(msgName, "r");

	files.msgCount = getSize(msgName);
	files.msg = malloc(files.msgCount * sizeof(int));

	if (files.msgCount == 0 || files.keyCount == 0) {
		printMessage(TYPE_ERROR, ERROR_UNKNOWN);
		exit(0);
	} else {
		if (fileExists(encryptedFileName) == 1) {
			remove(encryptedFileName);
		}
		
		iHolder.lastIndex = 30000; // High number so first distance is OK
		
		while (!feof(msgFile) && fscanf(msgFile, "%c", &iHolder.currentChar) == 1) {
			iHolder.currentIndex = findIntRepresentation(files, iHolder, d);
			
			if (iHolder.currentIndex != 0) {
				writeIntToFile(iHolder.currentIndex, encryptedFileName);
			} else {
				writeCharToFile(iHolder.currentChar, encryptedFileName);
			}
			iHolder.lastIndex = iHolder.currentIndex;
		}
	}
	free(files.msg);
	free(files.key);
	fclose(msgFile);
}

int findIntRepresentation(FileContainer files, IndexHolder iHolder, int d) {
	int i = 0;
	int diff = 0;
	
	if (isupper(iHolder.currentChar)) { // Check if char is uppercase
		iHolder.currentChar = tolower(iHolder.currentChar);
		for (i = 0; i <= files.keyCount; i++) {
			if (iHolder.currentChar == files.key[i]) {
				iHolder.currentIndex = i;
				diff = makePositive(iHolder.lastIndex - iHolder.currentIndex);
				if (diff >= d) {
					return ((iHolder.currentIndex + 1) * (-1));
				}
			}
		}
		printMessage(TYPE_ERROR, ERROR_INVALID_KEY);
		remove(decryptedFileName);
		exit(0);
	} else if (islower(iHolder.currentChar)) {
		for (i = 0; i <= files.keyCount; i++) {
			if (iHolder.currentChar == files.key[i]) {
				iHolder.currentIndex = i;
				diff = makePositive(iHolder.lastIndex - iHolder.currentIndex);
				if (diff >= d) {
					return (iHolder.currentIndex + 1);
				}
			}
		}
		printMessage(TYPE_ERROR, ERROR_INVALID_KEY);
		remove(decryptedFileName);
		exit(0);
	}
	
	return 0;
}

int makePositive(int i) {
	if (i < 0) {
		i *= (-1);
	}
	return i;
}

void decodeFile (FileContainer files, char * msgName) {
	int currentInt;
	char currentChar;

	FILE* msgFile = fopen(msgName, "r");

	if (files.msgCount == 0 || files.keyCount == 0) {
		printMessage(TYPE_ERROR, ERROR_UNKNOWN);
	} else {
		if (fileExists(decryptedFileName) == 1) {
			remove(decryptedFileName);
		}
		
		while (!feof(msgFile) && fscanf(msgFile, "%c", &currentChar) == 1) {
			if (currentChar == '[') {
				fscanf(msgFile, "%d", &currentInt);
				currentChar = findCharRepresentation(files, currentInt);
				writeCharToFile(currentChar, decryptedFileName);
			} else if (currentChar != ']') {
				writeCharToFile(currentChar, decryptedFileName);
			}
		}
	}
	free(files.msg);
	free(files.key);
	fclose(msgFile);
}

char findCharRepresentation(FileContainer files, int index) {
	char c;
	
	if (index == 0) {
		printMessage(TYPE_ERROR, ERROR_UNKNOWN);
		exit(0);
	} else {
		if (index < 0) {
			index *= (-1);
			c = files.key[index - 1];
			c = toupper(c);
		} else if (index > 0) {
			c = files.key[index -1];
		}
	}
	
	return c;
}

