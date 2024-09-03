#!/bin/bash

# Компиляция и компоновка
gcc -std=c99 -Werror -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -c *.c -g3
gcc -o app.exe *.o -lm
