#!/bin/bash

# Добавление "молчаливости" скрипту
exec > /dev/null 2>&1

# Создание временного файла для хранения вывода
in_bin="/tmp/tmp_1"
out_bin="/tmp/tmp_2"
output="/tmp/tmp_3"

# Считываем аргументы строки из файла
argv=()
argc=0

arg_line=$(cat "$2")
for arg in $arg_line;do
	argv+=("$arg")
	((argc++))
done

# Кусок преобразования в файл нужного расширения
if ((argc == 1));then
	argv[0]=../../"${argv[0]}"
elif ((argc == 2));then
	filepath=../../"${argv[1]}"
	# Извлечение имени файла без расширения
	new_extension=".txt"
	new_filepath="${filepath%.*}${new_extension}"
	../../app.exe import "$new_filepath" "$in_bin"
	argv[1]="$in_bin"
elif ((argc == 4));then
	filepath=../../"${argv[1]}"
	# Замена расширения файла на.txt
	new_extension=".txt"
	new_filepath="${filepath%.*}${new_extension}"
	../../app.exe import "$new_filepath" "$in_bin"
	argv[1]="$in_bin"
	argv[2]="$out_bin"
fi

if ! ../../app.exe "${argv[@]}" < "$1" > "$output";then
	exit 0
else
	exit 1
fi
