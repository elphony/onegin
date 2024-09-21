#include <stdio.h>

#include "output.h"

void output(Text* str_array) {

    for (size_t i = 0; i < str_array->str_num; ++i) {
        printf("%s\n", str_array->str_array[i].str);
    }

}