CC = gcc
CFLAGS = -Wall -std=c99

default: src/main.o
	@$(CC) -o erat src/main.o
