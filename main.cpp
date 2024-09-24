#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#include "input.h"
#include "compare.h"
#include "output.h"
#include "qsort.h"
#include "parse_cmd_arg.h"

// аргумент командной строки - имя файла и направление
// передавать указатели
// деструктор

// перейти на qsort -- указатель на функцию
// функция вывода - вроде готово
// нэйминг (функции с глаголов) - поменяла целую одну
// обратная сортировка - кажется работает
// написать нормальный свап ААААААААААААААААААААААААААААААААААА - победа
// возможно добавить в Text название файла - Ян сказал бессмыслено и нафиг не надо
// переписать НАФИГ ВЕСЬ ИНПУТ - победа

enum FlagCommand {
    FLAG_F = 1,
    FLAG_R,
    NO_COMMAND = -1
};

const Command options[] = {
    {"forward", FLAG_F},
    {"reverse", FLAG_R},
};


int main(int argc, const char** argv) {

    const char* name_file = argv[1];
    String file = input_file(name_file);
    Text onegin = split_file(&file);

    for (int i = 2; i < argc; i++) {
        int cmd = parse_cmd_line(argv[i], options, sizeof(options)/sizeof(options[0]));

        switch(cmd) {
            case FLAG_F:
                q_sort(onegin.str_array, 0, onegin.str_num - 1, sizeof(String), compare_forward);
                output(&onegin);
                break;

            case FLAG_R:
                q_sort(onegin.str_array, 0, onegin.str_num - 1, sizeof(String), compare_reverse);
                output(&onegin);
                break;

            default:
                printf("ыбыбыбыбы");
       }
    }

    free(onegin.str_array);
    free(file.str);
}


