#include <stdio.h>
#include <assert.h>

#include "parse_cmd_arg.h"

int parse_cmd_line(const char* string_cmd, const Command options[], size_t len) {
    assert(string_cmd != NULL);
    for(size_t i = 0; i < len; i++) {
        if (((string_cmd[0] == '-') && (strcmp(options[i].com, (string_cmd + 1)) == 0)) || 
            ((string_cmd[0] == '-') && (string_cmd[1] == '-') && (strcmp(options[i].com, (string_cmd + 2)) == 0))) {
            return options[i].flag;

        }
    }
    return -1;
}