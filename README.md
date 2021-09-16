# `pomodoro`

C program for people who like using the pomodoro technique
for study, work, etc.

## Configuration and Usage

You should probably keep the source code as it is the best way to modify this
software, notification events are handled by a simple shell script that is
called at runtime, assuming you have some sort of POSIX complaint shell, just
edit `notify` to your liking, an example is playing a sound notification
with mpv or using `xsetroot` to inform you through a status bar, this is up to
the user, by default an `echo` command is used.

A great program to use alongside `pomodoro` is the simple notification program
`herbe` (https://github.com/dudik/herbe)
