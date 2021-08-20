CC=gcc
CFLAGS=-g -Wall

all:clean test

emulator:
	$(CC) emu/main.c emu/exec.c $(CFLAGS) -o emulator

test:emulator
	./emulator

clean:
	rm emulator
