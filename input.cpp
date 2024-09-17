#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#include <stdlib.h>

#include "input.h"

String input_file(char* name_file) {
    FILE* f = fopen(name_file, "rb");
    assert(f != nullptr && "Error opening the file");

    String res = {};
    struct stat file_stat = {};
    
    fstat(fileno(f), &file_stat);
    assert(errno == 0 && "Information reading error");

    res.len = (size_t)file_stat.st_size;
    res.str = (char*)calloc(res.len + 1, sizeof(char));
    assert(res.str != nullptr && "Memory allocation error");

    size_t count = fread(res.str, sizeof(char), res.len, f);
    assert(count == res.len && "Error reading the file");

    res.str[res.len] = '\0';

    fclose(f);

    return res; 
}

// получаем строку всего файла
// считаем количество строк по \n
// выделяем необходимое количество памяти на указатели
// снова идем по массиву и ищем строки по \r и \n
// каждую новую сохраняем в массив указателей вместе с длиной 
Text file_to_array(String file_str) {

    Text res = {nullptr, 0};

    for (size_t i = 0; i < file_str.len; ++i) {
        if (file_str.str[i] == '\n') {
            res.str_num++;
            file_str.str[i] = '\0';
        }
    }

    res.str_array = (String*)calloc(res.str_num + 1, sizeof(String));
    assert(res.str_array != nullptr && "Memory allocation error");

    size_t count_str = 0;
    int len_str = -1;
    int ind = 0;

    res.str_array[0] = {file_str.str, 0};

    for (size_t i = 0; i < file_str.len-1; ++i) {
        printf("%zu. %d -- ", i, file_str.str[i]);
        if (file_str.str[i] == '\0') {
            count_str++;

            res.str_array[count_str-1].len = i - len_str;
            len_str = i;
            ind = i;

            res.str_array[count_str] = {file_str.str + i + 1, 0};
        }
    }
    res.str_array[count_str].len = ind - len_str;

    return res;
}