#!/bin/bash

./clean.sh

# Компиляция с включением покрытия кода
gcc -fprofile-arcs -ftest-coverage ./main.c -o app.exe -lm

# Запуск тестов
for test_file in ./func_tests/data/*in.txt; do
    ./app.exe < "$test_file" > /dev/null
done

# Сбор данных о покрытии
lcov --capture --directory . --output-file coverage.info

# Фильтрация данных покрытия для удаления ненужных файлов
lcov --remove coverage.info '/func_test/*' -o coverage.info

# Генерация HTML отчета
genhtml coverage.info --output-directory coverage_report

echo "Отчет о покрытии создан в директории coverage_report."
