#ifndef SORT_H
#define SORT_H

enum Mode {
    FORWARD =  1,
    REVERSE = -1
};

#include "input.h"

typedef int (*compare_func)(void* str1, void* str2);

int compare_forward(void* str1, void* str2);

int compare_reverse(void* str1, void* str2);

int compare_str(String* str1, String* str2, Mode option);

void skip(String str1, String str2, size_t* i, size_t* j, Mode option);

#endif //SORT_H