#pragma once

int checkFiles(char **argv) {
	int msg = fileExists(argv[1]);
	int key = fileExists(argv[2]);
	
	return (msg * key);
}

int fileExists (const char *fileName) {
	if(access(fileName, F_OK) != -1) {
		return 1;
	}

	printMessage(TYPE_ERROR, ERROR_FILE_NOT_FOUND);
	return 0;
}

char** openAndReadFiles(char **argv) {
	FILE* messageFile = fopen(argv[1], "r");
	FILE* keyFile = fopen(argv[2], "r");
	
	char** files;
	char* message;
		// write messageFile to message
	char* key;
		// write keyFile to key
	
	files[0] = message;
	files[1] = key;
	
	// Write files to *file and *key, put in files**
	printMessage(TYPE_INFO, INFO_FILES_OK);
	return files;
}

