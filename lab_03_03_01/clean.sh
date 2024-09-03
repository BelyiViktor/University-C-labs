#!/bin/bash

# Придадим скрипту абсолютную бесшумность
exec > /dev/null 2>&1

# Удаление данных покрытия
rm -rf coverage_report
rm -f coverage.info
rm *.gcda *.gcno

# Удаление файлов сборки проекта
rm ./*.o ./*.exe
