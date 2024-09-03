#!/bin/bash

# Дадим скрипту "молчаливость"
exec > /dev/null 2>&1

# Пути к файлам
file1="$1"
file2="$2"

# Проверка результата сравнения
if diff "$file1" "$file2" ; then
    exit 0
else
    exit 1
fi
