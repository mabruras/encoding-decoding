// #include "../lib/globallib.h"
#pragma once

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#include "fileHandling.h"
#include "messages.h"
#include "secretCoder.h"
#include "userInteraction.h"
#include "files.h"

int inputNotValid(char c);

char getUserInput();

int encodeOrDecode(char input);

