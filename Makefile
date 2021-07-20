CC=clang
CFLAGS=-O2 -pipe -Wall -std=c99 -pedantic

pomodoro: pomodoro.c
	$(CC) $(CFLAGS) pomodoro.c -o pomodoro

clean:
	rm pomodoro

install: pomodoro
	mkdir -p /usr/share/pomodoro/
	cp notify.sh /usr/share/pomodoro/notify.sh
	cp pomodoro /usr/bin/pomodoro
	chmod 755 /usr/bin/pomodoro

uninstall:
	rm -r /usr/share/pomodoro/
	rm /usr/bin/pomodoro
