#pragma once

void encodeOrDecode(char **argv, char input) {
	if (input == 'e' || input == 'E') {
		encodeFile(argv);
	} else {
		decodeFile(argv);
	}
}

int inputNotValid(char c) {
	if (c == 'd' || c == 'D' || c == 'e' || c == 'E' || c == 'q') {
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

