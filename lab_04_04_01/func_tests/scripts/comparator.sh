#!/bin/bash

# Придадим скрипту безшумность
exec > /dev/null 2>&1

# Сравнениваем содержимое.
if cmp -s "$1" "$2" ; then
    exit 0
else
    exit 1
fi
