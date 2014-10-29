#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../lib/messages.h"
#include "../lib/secretCoder.h"
#include "../lib/userInteraction.h"
#include "../lib/fileHandling.h"

/*
* Takes in the following parameters
* File - The file to en-/decode
* Key - file containing the key used for en-/decoding the file
*/
int main (int argc, char **argv) {
	
	// Check if the program was started with two parameters (file and key)
	if (argc == 3){
		if (checkFiles(argv) != 0) {
			openAndReadFiles(argv);
			char action = getUserInput();
			if (action == 'q') 
				{ exit(0); }
			encodeOrDecode(argv, action);
		}
	} else {
		printMessage(TYPE_ERROR, ERROR_PARAMETERS);
	}

	return 0;
}

