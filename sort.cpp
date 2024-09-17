#include <ctype.h>

#include "input.h"
#include "sort.h"

// Возвращает разницу ASCII кодов первых отличчающихся символов
// Если она меньше нуля то str1 выше str2
// Если она равна нулю то str1 тождественно str2
// Если она больше нуля то str1 ниже str2
int compare_str(String str1, String str2) {
    size_t i = 0;
    int res = tolower(str1.str[0]) - tolower(str2.str[0]);

    while (!(str1.str[i] == '\0') && !(str2.str[i] == '\0') && (res == 0)) {
        i++;
        res = tolower(str1.str[i]) - tolower(str2.str[i]);
    }

    return res;
}

// Получаем весь массив строк
// Реализуем обычную сортировку но вместо знаков сравнения compare_str
void sort_str(Text text) {
    for (size_t i = 0; i < text.str_num; i++) {
        for (size_t j = 0; j < text.str_num - 1; j++) {
            if (compare_str(text.str_array[j], text.str_array[j + 1]) > 0) {
                swap(&text.str_array[j].str, &text.str_array[j+1].str);
            }
        }
    }
}

// Меняем местами два указателя
void swap(char** pointer1, char** pointer2) {
    char* new_pointer = *pointer1;
    *pointer1 = *pointer2;
    *pointer2 = new_pointer;
}