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

int checkFiles(char **argv) {
	int msg = fileExists(argv[1]);
	int key = fileExists(argv[2]);

	if (msg == 0 || key == 0) {
		printMessage(TYPE_ERROR, ERROR_FILE_NOT_FOUND);
	}

	return (msg * key);
}

int fileExists (const char *fileName) {
	if(access(fileName, F_OK) != -1) {
		return 1;
	}

	return 0;
}

int getSize(char* v) {
	struct stat st;

	stat(v, &st);
	int size = st.st_size;

	return size;
}

FileContainer openAndReadKey(char *keyName) {
	FileContainer files;
	
	files = collapseKey(keyName);
	printMessage(TYPE_INFO, INFO_KEY_LOADED);

	return files;
}

