#!/bin/bash

# Добавление "молчаливости" скрипту
exec > /dev/null 2>&1

# Создание временного файла для хранения вывода
output=$(mktemp /tmp/tmp_XXXXXX)

# Запуск программы с тестовыми данными
../../app.exe < "$1" > "$output"

# Сравнение полученных данных с тестовыми
if ./comparator.sh "$output" "$2" ; then
	exit 0
else
	exit 1
fi

