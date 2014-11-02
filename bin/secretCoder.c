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

FileContainer collapseKey(char *keyName) {
	char currentChar;
	FILE* keyFile = fopen(keyName, "r");
	FileContainer tempContainer;
	if (keyFile == NULL) {
		printMessage(TYPE_ERROR, ERROR_INVALID_KEY);
	} else {
		tempContainer.key = malloc(getSize(keyName) * sizeof(int));
		tempContainer.keyCount = 0;

		printf("Key: ");
		while (!feof(keyFile) && fscanf(keyFile, "%c", &currentChar) == 1) {
			if (isalpha(currentChar)) {
				if (isupper(currentChar)) {
					currentChar = tolower(currentChar);
				}
				strcat(tempContainer.key, &currentChar);
				tempContainer.keyCount++;
printf("%c", currentChar);
			}
		}
	}
	printf("\n\n");
	return tempContainer;
}

void writeIntToFile(int number) {
	FILE* encryptedFile = fopen(encryptedFileName, "a");
	if (encryptedFile == NULL) {
		printMessage(TYPE_ERROR, ERROR_LOAD_FILE);
	} else {
		fprintf(encryptedFile, "%c", '[');
		fprintf(encryptedFile, "%d", number);
		fprintf(encryptedFile, "%c", ']');
	}
	fclose(encryptedFile);
}

void writeCharToFile(char c) {
	FILE* encryptedFile = fopen(encryptedFileName, "a");
	if (encryptedFile == NULL) {
		printMessage(TYPE_ERROR, ERROR_INVALID_KEY);
	} else {
		fprintf(encryptedFile, "%c", c);
	}
	fclose(encryptedFile);
}

void encodeFile (FileContainer files, char * msgName) {

	int currentInt;
	char currentChar;
	FileContainer tempContainer;
	FILE* msgFile = fopen(msgName, "r");
	
	tempContainer.msgCount = getSize(msgName);
	tempContainer.msg = malloc(tempContainer.msgCount * sizeof(int));
	files.msg = tempContainer.msg;
	files.msgCount = tempContainer.msgCount;


printf("%d", tempContainer.msgCount);
	if (files.msgCount == 0 || files.keyCount == 0) {
		printMessage(TYPE_ERROR, ERROR_UNKNOWN);
	} else {
		if (fileExists(encryptedFileName) == 1) {
			remove(encryptedFileName);
		}
		
		while (!feof(msgFile) && fscanf(msgFile, "%c", &currentChar) == 1) {
			
			currentInt = findIntRepresentation(files, currentChar);
			
			if (currentInt != 0) {
				writeIntToFile(currentInt);
			} else {
				writeCharToFile(currentChar);
			}
		}
	}
	fclose(msgFile);
}

int findIntRepresentation(FileContainer files, char c) {
	int i = 0;
	
	if (isupper(c)) { // Check if char is uppercase
		c = tolower(c);
		for (i = 0; i <= files.keyCount; i++) {
			if (c == files.key[i]) {
				return ((i + 1) * (-1));
			}
		}
	} else if (islower(c)) {
		for (i = 0; i <= files.keyCount; i++) {
			if (c == files.key[i]) {
				return (i + 1);
			}
		}
	}
	
	return 0;
}

void decodeFile (FileContainer files, char * msgName) {
	printf("decoding...\n");
	int i = 0;
	while (i <= files.msgCount) {
		i++;
	}
}

