// #include "../lib/globallib.h"
#pragma once


#define TYPE_ERROR "[ERROR]"
#define TYPE_INPUT "[INPUT]"
#define TYPE_INFO "[INFO]"
#define ERROR_PARAMETERS "You need to send in two files; \n* File to en-/decode \n* File containing the decryption key."
#define ERROR_FILE_NOT_FOUND "One of the files was not found!"
#define ERROR_INVALID_KEY "The key was not valid, missing one or more operands"
#define ERROR_LOAD_FILE "One or both of the files is corrupt."
#define ERROR_SAVE_FILE "Something went wrong; could not save file."
#define ERROR_UNKNOWN "Unexpected error. Please restart the program..."
#define INFO_FILE_LOADED "File loaded successfully"
#define INFO_KEY_LOADED "Key loaded successfully"
#define INFO_ENCODE_OR_DECODE "Do you want to encode or decode this file (e/d)? [q for quit]:"
#define INFO_FILES_OK "Both files was read without interruption."
#define INFO_ENCODING_START "Starting to encode the message..."
#define INFO_DECODING_START "Starting to decode the message..."
#define INFO_ENCODING_END "Encoding of message complete!"
#define INFO_DECODING_END "Decoding of message complete!"
#define CHOICE_EXIT "You choose to quit.\nShutting down program..."
#define INFO_SAFETY_LEVEL "What safety level do you want [1-9]? \n(Higher number requires larger key):"

