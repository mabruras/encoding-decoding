// #include "../lib/globallib.h"
#pragma once

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

void printMessage(char* type, char* msg);

int inputNotValid(char c);

int getWantedSecLvl();

int secLvlNotValid(char c);

int toInt(char c);

char getUserInput();

int encodeOrDecode(char input);

