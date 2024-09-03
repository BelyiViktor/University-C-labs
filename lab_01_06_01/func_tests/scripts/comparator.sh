#!/bin/bash

# Дадим скрипту "молчаливость"
exec > /dev/null 2>&1

# Пути к файлам
file1="$1"
file2="$2"

# Создание временных файлов в /tmp
tmpfile1=$(mktemp /tmp/file1_XXXXXX)
tmpfile2=$(mktemp /tmp/file2_XXXXXX)

# Извлечение чисел из файлов, включая числа в экспоненциальной записи
if [ -s "$file1" ]; then
    grep -oE "[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?" "$file1" > "$tmpfile1"
fi
if [ -s "$file2" ]; then
    grep -oE "[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?" "$file2" > "$tmpfile2"
fi

# Сравнение чисел
cmp -s "$tmpfile1" "$tmpfile2"

# Проверка результата сравнения
if cmp -s "$tmpfile1" "$tmpfile2" ; then
    exit 0
else
    exit 1
fi

