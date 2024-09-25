#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>

#include "input.h"
#include "compare.h"
#include "output.h"
#include "qsort.h"
#include "parse_cmd_arg.h"

// аргумент командной строки - имя файла и направление

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
    FLAG_D,
    FLAG_H,
    NO_COMMAND = -1
};

const Command options[] = {
    {"forward", FLAG_F},
    {"reverse", FLAG_R},
    {"default", FLAG_D},
    {"help", FLAG_H}
};

Text copy_text(Text* onegin);

int main(int argc, const char** argv) {

    const char* name_file = argv[1];
    String file = input_file(name_file);
    Text onegin = split_file(&file);
    Text onegin_d = copy_text(&onegin);

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
            
            case FLAG_D:
                output(&onegin_d);
                break;

            default:
                printf("The command was not found\n");
                break;
       }
    }
    if (argc < 3) {
        printf("The command was not found\n");
    }

    free(onegin_d.str_array);
    free(onegin.str_array);
    free(file.str);
}

Text copy_text(Text* onegin) {
    Text res = {NULL, onegin->str_num};
    res.str_array = (String*)calloc(onegin->str_num, sizeof(String));

    for (size_t i = 0; i < onegin->str_num; ++i) {
        res.str_array[i].str = onegin->str_array[i].str;
    }

    return res;
}