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
		return 0; 	// Valid
	}
	
	return 1;		// Not valid
}

int getWantedSecLvl() {
	char userInput;
	do {
		printMessage(TYPE_INPUT, INFO_SAFETY_LEVEL);
		scanf("%c", &userInput);
		getchar();
	} while (secLvlNotValid(userInput) == 1);
	return toInt(userInput);
}

int secLvlNotValid(char c) {
	if (isdigit(c) && c != '0') {
		return 0;	// Valid
	}
	return 1;		// Not valid
}

int toInt(char c){ 
	return (int) c -'0';
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

