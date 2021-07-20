CC=clang
CFLAGS=-O2 -pipe -Wall -std=c99 -pedantic

pomodoro: pomodoro.c
	$(CC) $(CFLAGS) pomodoro.c -o pomodoro
