#ifndef INPUT_H
#define INPUT_H

#include <stddef.h>

struct String {
    char* str;
    size_t len;
};

struct Text {
    String* str_array;
    size_t str_num;
};

String input_file(const char* name_file);

Text split_file(String* file_str);

#endif //INPUT_H