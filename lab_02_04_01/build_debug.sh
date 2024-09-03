#!/bin/bash

# Компиляция и компоновка
<<<<<<<< HEAD:lab_02_04_01/build_debug.sh
gcc -std=c99 -Werror -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -c main.c -g3
gcc -o app.exe main.o -lm
========
gcc -std=c99 -Werror -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -c ./*.c -g3 -D_POSIX_C_SOURCE=200112L
gcc -o app.exe ./*.o -lm
>>>>>>>> main:lab_05_04_01/build_debug.sh
