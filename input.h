#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>

struct String {
    char* str;
    size_t len;
};

struct Text {
    String* str_array;
    size_t str_num;
};

String input_file(char* name_file);

Text file_to_array(String file_str);

#endif //INPUT_H