CC=cc
CFLAGS=-O2 -pipe -Wall -std=c99 -pedantic
LDFLAGS=-static

pomodoro: pomodoro.c
	$(CC) $(CFLAGS) $(LDFLAGS) pomodoro.c -o pomodoro

install: pomodoro
	mkdir -p /usr/share/pomodoro/
	cp notify.sh /usr/share/pomodoro/notify.sh
	cp pomodoro /usr/bin/pomodoro
	chmod 755 /usr/bin/pomodoro

uninstall:
	rm -r /usr/share/pomodoro/
	rm /usr/bin/pomodoro

clean:
	rm pomodoro

