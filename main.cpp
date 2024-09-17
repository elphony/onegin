#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#include "input.h"
#include "sort.h"

// если сразу после чтения приводить все буквы к одному регистру
// то потом при выводе текст будет неприятный
// а в каждом сравнении проверять регистр звучит как очень плохая идея (будет повторяться много раз)
// получается что надо сохранять регистры????? бред - много памяти и доп проверки при выводе

// функция вывода
// аргумент командной строки
// обратная сортировка
// перейти на qsort -- указатль на функцию

int main() {
    char name_file[] = "test.txt";  // const
    String file = input_file(name_file);
    Text onegin = file_to_array(file); //указатель

    //sort_str(onegin);

    for (size_t i = 0; i < onegin.str_num; ++i) {
        printf("%zu\n", onegin.str_array[i].len);
    }

    free(onegin.str_array);
    free(file.str);
}

