#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

#include <stdlib.h>

#include "input.h"

String input_file(const char* name_file) {
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
Text split_file(String file_str) {
    
    Text res = {nullptr, 0};
    
    for (size_t i = 0; i < file_str.len; ++i) {
        if (file_str.str[i] == '\n') {
            res.str_num++;
        }
    }
    res.str_num++;

    res.str_array = (String*)calloc(res.str_num + 1, sizeof(String));

    char* token = strtok(file_str.str, "\n");
    size_t index = 0;

    while (token != NULL)
    {
        res.str_array[index].str = token;
        res.str_array[index].len = strlen(token);
        token = strtok(NULL, "\n");
        index++;
    }

    return res;
}