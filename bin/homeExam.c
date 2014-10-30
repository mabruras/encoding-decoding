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

/*
* Takes in the following parameters
* File - The file to en-/decode
* Key - file containing the key used for en-/decoding the file
*/
int main (int argc, char **argv) {
	
	// Check if the program was started with two parameters (file and key)
	if (argc == 3){
		FileContainer files;
		
		files.msg = argv[1];
		files.key = argv[2];

		if (checkFiles(files) != 0) {
			files = openAndReadFiles(files);
			char action = getUserInput();
			
			int choice = encodeOrDecode(action);

			switch (encodeOrDecode(action)) {
			case 0:
				printMessage(TYPE_INFO, CHOICE_EXIT);
				exit(0);
			case 1:
				printMessage(TYPE_INFO, INFO_ENCODING_START);
				encodeFile(files);
				printMessage(TYPE_INFO, INFO_ENCODING_END);
				break;
			case 2:
				printMessage(TYPE_INFO, INFO_DECODING_START);
				decodeFile(files);
				printMessage(TYPE_INFO, INFO_DECODING_END);
				break;
			default:
				break;
			}
			
			printf("hello");
		}
	} else {
		printMessage(TYPE_ERROR, ERROR_PARAMETERS);
	}

	return 0;
}

