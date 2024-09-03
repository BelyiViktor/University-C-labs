#!/bin/bash

# Придадим скрипту безшумность
exec > /dev/null 2>&1

# Пути к файлам.
file1="$1"
file2="$2"


# Создаём временные файлы в /tmp.
tmpfile1=$(mktemp /tmp/file1_XXXXXX)
tmpfile2=$(mktemp /tmp/file2_XXXXXX)

# Записываем строку после первого вхождения подстроки и саму подстроку
grep -o "Result: .*$" "$file1" | head -n 1 > "$tmpfile1"
grep -o "Result: .*$" "$file2" | head -n 1 > "$tmpfile2"

# Определяем номер следующей строки после строки, в которой подстрока.
# Если таковой нет, сразу завершаем сравнение с ошибкой.
# У первого файла.
number_line_after_in_text1=$(grep -n "Result: " "$1" | head -n 1 | cut -d: -f1)
if [[ -z $number_line_after_in_text1 ]]; then
    exit 1
fi
number_line_after_in_text1=$((number_line_after_in_text1 + 1))

# У второго файла.
number_line_after_in_text2=$(grep -n "Result: " "$2" | head -n 1 | cut -d: -f1)
if [[ -z $number_line_after_in_text2 ]]; then
    exit 1
fi
number_line_after_in_text2=$((number_line_after_in_text2 + 1))


# Записываем все строки после той, в которой первое вхождение подстроки.
# Для первого файла.
tail -n +"$number_line_after_in_text1" "$file1" >> "$tmpfile1"
# Для второго файла.
tail -n +"$number_line_after_in_text2" "$file2" >> "$tmpfile2"

# Сравнениваем содержимое.
if cmp -s "$tmpfile1" "$tmpfile2" ; then
    # Удаляем временные файлы
    rm -f "$tmpfile1" "$tmpfile2"
    exit 0
else
    # Удаляем временные файлы
    rm -f "$tmpfile1" "$tmpfile2"
    exit 1
fi
