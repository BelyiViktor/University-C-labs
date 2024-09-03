#!/bin/bash

./clean.sh

# Компиляция с включением покрытия кода
gcc -fprofile-arcs -ftest-coverage ./*.c -o app.exe -lm

test_dir_data="./func_tests/data/"

# Определение количества тестовых файлов
pos_test_files=0
for file in "$test_dir_data"*; do
    if [[ $file == *pos_[0-9]*_in.txt ]]; then
        ((pos_test_files++))
    fi
done

neg_test_files=0
for file in "$test_dir_data"*; do
    if [[ $file == *neg_[0-9]*_in.txt ]]; then
        ((neg_test_files++))
    fi
done

# Запуск тестов
for ((i=1; i <= ${pos_test_files}; i++)); do
    file_with_args=./func_tests/data/pos_0"$i"_args.txt 
    file_of_stream_in=./func_tests/data/pos_0"$i"_in.txt 

    # Создание временного файла для хранения вывода
    in_bin="/tmp/tmp_1"
    out_bin="/tmp/tmp_2"
    output="/tmp/tmp_3"

    # Считываем аргументы строки из файла
    argv=()
    argc=0

    arg_line=$(cat "$file_with_args")
    for arg in $arg_line;do
        argv+=("$arg")
        ((argc++))
    done

    # Кусок преобразования в файл нужного расширения
    if ((argc == 1));then
        argv[0]="${argv[0]}"
    elif ((argc == 2));then
        filepath="${argv[1]}"
        # Извлечение имени файла без расширения
        new_extension=".txt"
        new_filepath="${filepath%.*}${new_extension}"
        ./app.exe import "$new_filepath" "$in_bin"
        argv[1]="$in_bin"
    elif ((argc == 4));then
        filepath="${argv[1]}"
        # Замена расширения файла на.txt
        new_extension=".txt"
        new_filepath="${filepath%.*}${new_extension}"
        ./app.exe import "$new_filepath" "$in_bin"
        argv[1]="$in_bin"
        argv[2]="$out_bin"
    fi

    # Запуск программы с тестовыми данными
    ./app.exe "${argv[@]}" < "$file_of_stream_in" > "$output"
done

# Запуск тестов
for ((i=1; i <= ${neg_test_files}; i++)); do
    file_with_args=./func_tests/data/neg_0"$i"_args.txt 
    file_of_stream_in=./func_tests/data/neg_0"$i"_in.txt 

    # Создание временного файла для хранения вывода
    in_bin="/tmp/tmp_1"
    out_bin="/tmp/tmp_2"
    output="/tmp/tmp_3"

    # Считываем аргументы строки из файла
    argv=()
    argc=0

    arg_line=$(cat "$file_with_args")
    for arg in $arg_line;do
        argv+=("$arg")
        ((argc++))
    done

    # Кусок преобразования в файл нужного расширения
    if ((argc == 1));then
        argv[0]="${argv[0]}"
    elif ((argc == 2));then
        filepath="${argv[1]}"
        # Извлечение имени файла без расширения
        new_extension=".txt"
        new_filepath="${filepath%.*}${new_extension}"
        ./app.exe import "$new_filepath" "$in_bin"
        argv[1]="$in_bin"
    elif ((argc == 4));then
        filepath="${argv[1]}"
        # Замена расширения файла на.txt
        new_extension=".txt"
        new_filepath="${filepath%.*}${new_extension}"
        ./app.exe import "$new_filepath" "$in_bin"
        argv[1]="$in_bin"
        argv[2]="$out_bin"
    fi

    # Запуск программы с тестовыми данными
    ./app.exe "${argv[@]}" < "$file_of_stream_in" > "$output"
done

# Сбор данных о покрытии
lcov --capture --directory . --output-file coverage.info

# Фильтрация данных покрытия для удаления ненужных файлов
lcov --remove coverage.info '/func_test/*' -o coverage.info

# Генерация HTML отчета
genhtml coverage.info --output-directory coverage_report

echo "Отчет о покрытии создан в директории coverage_report."
