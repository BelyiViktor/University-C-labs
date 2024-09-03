#!/bin/bash

# Добавление "молчаливости" скрипту
exec > /dev/null 2>&1

# Запуск программы с тестовыми данными
../../app.exe < "$1" > /dev/null

if ! ../../app.exe < "$1" > /dev/null; then
	exit 0
else
	exit 1
fi

