#!/bin/sh

POMODORO_STATE=$@

if [ "$POMODORO_STATE" = "w" ]; then
    echo ping
elif [ "$POMODORO_STATE" = "i" ]; then
    echo pong
fi
