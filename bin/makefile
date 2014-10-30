CC=gcc
CFLAGS= -std=c11

#files
OBJECTS = homeExam.o fileHandling.o secretCoder.o userInteraction.o
OUTPUT = HomeExam

all: $(OBJECTS)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(OBJECTS)

homeExam.o: homeExam.c
	$(CC) $(CFLAGS) -c $< -o $@

userInteraction.o: userInteraction.c
	$(CC) $(CFLAGS) -c $< -o $@

fileHandling.o: fileHandling.c
	$(CC) $(CFLAGS) -c $< -o $@

secretCoder.o: secretCoder.c
	$(CC) $(CFLAGS) -c $< -o $@
