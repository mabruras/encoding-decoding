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

int checkFiles(FileContainer files) {
	int msg = fileExists(files.msg);
	int key = fileExists(files.key);
	
	return (msg * key);
}

int fileExists (const char *fileName) {
	if(access(fileName, F_OK) != -1) {
		return 1;
	}

	printMessage(TYPE_ERROR, ERROR_FILE_NOT_FOUND);
	return 0;
}

int getSize(char* v) {
	struct stat st;

	stat(v, &st);
	int size = st.st_size;

	return size;
}

FileContainer openAndReadFiles(FileContainer files) {
	FileContainer tempContainer;

	FILE* keyFile = fopen(files.key, "r");
	files.key = malloc(getSize(files.key) * sizeof(int));
	tempContainer = collapseKey(keyFile);
	files.key = tempContainer.key;

	FILE* messageFile = fopen(files.msg, "r");
	files.msg = malloc(getSize(files.msg) * sizeof(int));
	tempContainer = readFile(messageFile);
	files.msg = tempContainer.msg;

	printMessage(TYPE_INFO, INFO_FILES_OK);

	return files;
}

