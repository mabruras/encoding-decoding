#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#include "../lib/fileHandling.h"
#include "../lib/messages.h"
#include "../lib/secretCoder.h"
#include "../lib/userInteraction.h"
#include "../lib/files.h"

FileContainer collapseKey(FILE* keyFile) {
	
	FileContainer tempContainer;
	char currentChar;
	
	while (!feof(keyFile) && fscanf(keyFile, "%c", &currentChar) == 1) {
		if (isalpha(currentChar)) {
			tempContainer.key += currentChar;
			tempContainer.keyCount++;
		}
	}
	
	return tempContainer;
}

FileContainer readFile(FILE* msgFile) {
	FileContainer tempContainer;
	char currentChar;
	
	while (!feof(msgFile) && fscanf(msgFile, "%c", &currentChar) ==1) {
		tempContainer.msg += currentChar;
	}
	
	return tempContainer;
}

void encodeFile (FileContainer files) {
	printf("encoding...\n");
	
}

void decodeFile (FileContainer files) {
	printf("decoding...\n");
}

