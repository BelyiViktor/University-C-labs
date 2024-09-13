#!/bin/bash

# Компиляция и компоновка
clang -std=c99 -Werror -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -fsanitize=memory -fno-omit-frame-pointer -g -c main.c -g3
clang -o app.exe main.o -lm -fsanitize=memory

