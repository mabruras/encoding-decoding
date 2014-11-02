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

void writeIntToFile(int number, char *fileName);

void writeCharToFile(char c, char *fileName);

void encodeFile (FileContainer files, char * msgName, int d);

int findIntRepresentation(FileContainer files, IndexHolder iHolder, int d);

int makePositive(int i);

void decodeFile (FileContainer files, char * msgName);

char findCharRepresentation(FileContainer files, int index);

