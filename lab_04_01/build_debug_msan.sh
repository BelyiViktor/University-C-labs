#!/bin/bash

# Компиляция и компоновка
clang -std=c99 -Werror -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -fsanitize=memory -fno-omit-frame-pointer -g -c *.c -g3
clang -o app.exe *.o -lm -fsanitize=memory
