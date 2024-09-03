#!/bin/bash

# Компиляция и компоновка
gcc -std=c99 -Werror -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -c ./*.c -D_POSIX_C_SOURCE=200112L
gcc -o app.exe ./*.o -lm
