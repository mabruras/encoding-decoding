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

void printMessage(char* type, char* msg){
	printf("%s : %s\n", type, msg);
}

int inputNotValid(char c) {
	if (c == 'd' || c == 'D'			// Decode
			|| c == 'e' || c == 'E' 	// Encode
			|| c == 'q' || c == 'Q') {	// Quit
		return 0; // Is valid
	}
	
	return 1; // Is not valid
}

char getUserInput() {
	char userInput;
	do {
		printMessage(TYPE_INPUT, INFO_ENCODE_OR_DECODE);
		scanf("%c", &userInput);
		getchar();
	} while (inputNotValid(userInput) == 1);
	
	return userInput;
}

int encodeOrDecode(char input) {
	if (input == 'q' || input == 'Q') {
		return 0;
	} else if (input == 'e' || input == 'E') {
		return 1;
	} else {
		return 2;
	}
}

