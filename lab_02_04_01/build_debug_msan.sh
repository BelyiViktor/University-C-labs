#!/bin/bash

# Компиляция и компоновка
<<<<<<<< HEAD:lab_02_04_01/build_debug_msan.sh
clang -std=c99 -Werror -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -fsanitize=memory -fno-omit-frame-pointer -g -c main.c -g3
clang -o app.exe main.o -lm -fsanitize=memory
========
clang -std=c99 -Werror -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -fsanitize=memory -fno-omit-frame-pointer -g -c *.c -g3
clang -o app.exe *.o -lm -fsanitize=memory
>>>>>>>> main:lab_03_05_01/build_debug_msan.sh
