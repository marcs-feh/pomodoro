# User Config
CC=cc
CFLAGS=-O2 -pipe -Wall -std=c89 -pedantic
LDFLAGS=-static
#==========#

pomodoro: pomodoro.c
	$(CC) $(CFLAGS) pomodoro.c -o pomodoro $(LDFLAGS)

install: pomodoro
	mkdir -p ~/.config/pomodoro/
	cp notify ~/.config/pomodoro/notify
	cp pomodoro /usr/bin/pomodoro
	chmod 755 /usr/bin/pomodoro

uninstall:
	rm -r ~/.config/pomodoro/
	rm /usr/bin/pomodoro

clean:
	rm pomodoro

