#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>

#include "input.h"
#include "compare.h"
#include "output.h"
#include "qsort.h"
#include "parse_cmd_arg.h"

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

void output_d(String* file);

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
            
            case FLAG_D:
                output_d(&file);
                break;

            default:
                printf("The command was not found\n");
                break;
       }
    }
    if (argc < 3) {
        printf("The command was not found\n");
    }

    free(onegin.str_array);
    free(file.str);
}

void output_d(String* file) {
    for (size_t i = 0; i < file->len; ++i) {  
        if (file->str[i] == '\0' && i > 0) { 
            printf("\n");
        }    
        else {
            printf("%c", file->str[i]);
        }
    }
}