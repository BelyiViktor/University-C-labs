#!/bin/bash +x

# Установка пути к тестовым файлам
test_dir_data="../data/"

# Установка пути к скриптам
test_dir_scripts="./"

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

# Переменная для подсчета всего количества тестов
total_tests=$((pos_test_files + neg_test_files))

# Переменная для подсчёта количества успешно пройденных тестов
counter=0

# Цикл по всем позитивным тестовым файлам
for i in $(seq 1 "$pos_test_files"); do
    # Получение имен входного и выходного файлов
    file_stream_in="${test_dir_data}pos_0${i}_in.txt"
    file_stream_out_expect="${test_dir_data}pos_0${i}_out.txt"
    file_args="${test_dir_data}pos_0${i}_args.txt"
    if "${test_dir_scripts}/pos_case.sh" "$file_stream_in" "$file_stream_out_expect" "$file_args"; then
	    echo -e "\033[32mПозитинвый тест № ${i} был пройден\033[0m"
	    ((counter+=1))
    else
	    echo -e "\033[31mПозитивный тест № ${i} был провален\033[0m"
    fi
done

# Цикл по всем негативным тестам
for i in $(seq 1 "$neg_test_files"); do
    # Получение имен входного файла
    file_stream_in="${test_dir_data}neg_0${i}_in.txt"
    file_args="${test_dir_data}neg_0${i}_args.txt"
    if "${test_dir_scripts}/neg_case.sh" "$file_stream_in" "$file_args"; then
            echo -e "\033[32mНегативный тест № ${i} был пройден\033[0m"
	    ((counter+=1))
    else
            echo -e "\033[31mНегативный тест № ${i} был провален\033[0m"
    fi
done

# Вывод сообщения о результатах тестирования
if [ $counter -eq $total_tests ];then
	echo -e "\033[32mТестирование было пройдено!\033[0m"
else
	echo -e "\033[31mТесирование было провалено\033[0m"
fi

exit $((total_tests - counter))
