#ifndef SORT_H
#define SORT_H

enum Mode {
    FORWARD =  1,
    REVERSE = -1
};

int compare_str(String str1, String str2, Mode option);

void sort_str(Text text, Mode option);

void swap(String* str1, String* str2);

void skip(String str1, String str2, size_t* i, size_t* j, Mode option);

#endif //SORT_H