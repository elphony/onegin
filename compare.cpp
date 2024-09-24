#include <ctype.h>

#include "input.h"
#include "compare.h"
#include "stdio.h"

int compare_forward(void* str1, void* str2) {
    return compare_str((String*)str1, (String*)str2, FORWARD);
}

int compare_reverse(void* str1, void* str2) {
    return compare_str((String*)str1, (String*)str2, REVERSE);
}

// Возвращает разницу ASCII кодов первых отличчающихся символов
// Если она меньше нуля то str1 выше str2
// Если она равна нулю то str1 тождественно str2
// Если она больше нуля то str1 ниже str2
// + пропускает пробелы и знаки препинания
int compare_str(String* str1, String* str2, Mode option) {
   
    size_t i = (option == FORWARD) ? 0 : str1->len - 1;
    size_t j = (option == FORWARD) ? 0 : str2->len - 1;
    int res = 0;

    skip(*str1, *str2, &i, &j, option);
    
    while (str1->str[i] != '\0' && str2->str[j] != '\0' && res == 0) {
        
        res = tolower(str1->str[i]) - tolower(str2->str[j]);
        i += option;
        j += option;
        skip(*str1, *str2, &i, &j, option);
    }
    //fprintf(stderr, "COMPARE_RESULT %s %s %d\n", str1->str, str2->str, res);
    return res;
}

// пропускает все символы кроме букв и меняет индекс
void skip(String str1, String str2, size_t* i, size_t* j, Mode option) {
    //fprintf(stderr, "i = %zu\nj = %zu\n", *i, *j);
    //fprintf(stderr, "str1[i] = %c\nstr2[j] = %c\n", str1.str[*i], str2.str[*j]);
    while (str1.str[*i] != '\0' && !isalnum(str1.str[*i])) {
        *i += option;
    }

    while (str2.str[*j] != '\0' && !isalnum(str2.str[*j])) {
        *j += option;
    }
}

