#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#include "input.h"
#include "sort.h"
#include "output.h"

// функция вывода
// аргумент командной строки - имя файла и направление
// перейти на qsort -- указатель на функцию
// передавать указатели
// деструктор


// нэйминг (функции с глаголов) - поменяла целую одну
// обратная сортировка - кажется работает
// написать нормальный свап ААААААААААААААААААААААААААААААААААА - победа
// возможно добавить в Text название файла - Ян сказал бессмыслено и нафиг не надо
// переписать НАФИГ ВЕСЬ ИНПУТ - победа

int main() {
    const char name_file[] = "test.txt";  
    String file = input_file(name_file);
    Text onegin = split_file(file); //указатель

    sort_str(onegin, REVERSE);
    
    output(onegin);

    free(onegin.str_array);
    free(file.str);
}

