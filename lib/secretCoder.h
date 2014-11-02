// #include "../lib/globallib.h"
#pragma once

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#include "../lib/fileHandling.h"
#include "../lib/messages.h"
#include "../lib/secretCoder.h"
#include "../lib/userInteraction.h"
#include "../lib/files.h"

FileContainer collapseKey(char *keyName);

int findIntRepresentation(FileContainer files, char c);

void writeIntToFile(int number);

void encodeFile (FileContainer files, char * msgName);

void decodeFile (FileContainer files, char * msgName);

