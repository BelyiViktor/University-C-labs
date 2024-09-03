#!/bin/bash

# Компиляция и компоновка
gcc -std=c99 -Werror -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -fsanitize=undefined -fno-omit-frame-pointer -g -c main.c -g3
gcc -o app.exe main.o -lm
