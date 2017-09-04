CC = gcc
CFLAGS = -Wall -std=c99 -lm

default: src/main.o
	$(CC) -o erat src/main.o $(CFLAGS) 
