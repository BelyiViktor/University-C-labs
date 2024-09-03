#!/bin/bash

# Компиляция и компоновка
gcc -std=c99 -Werror -Wall -Wvla -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -c main.c
gcc -o app.exe main.o -lm
