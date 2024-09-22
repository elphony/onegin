#include <ctype.h>

#include "input.h"
#include "sort.h"
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

    printf("str1_ = %p\nstr2_ = %p\n", str1, str2);
    printf("str1 = %p\nstr2 = %p\n", str1->str, str2->str);

    printf("========================================================\n");
    for (size_t k = 0; str1->str[k] != 0; ++k) {

        printf("[%zu]", k);
        putc(str1->str[k], stdout);
    }
    printf("========================================================\n");
    
    
    printf("========================================================\n");
    for (size_t k = 0; str2->str[k] != 0; ++k) {

        printf("[%zu]", k);
        putc(str2->str[k], stdout);
    }
    printf("========================================================\n");

    printf("str1 = %s\n", str1->str);
    printf("str2 = %s\n", str2->str);
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

// Получаем весь массив строк
// Реализуем обычную сортировку но вместо знаков сравнения compare_str
void sort_str(Text* text, Mode option) {
    for (size_t i = 0; i < text->str_num; i++) {
        for (size_t j = 0; j < text->str_num - 1; j++) {
            if (compare_str(&text->str_array[j], &text->str_array[j + 1], option) > 0) {
                //swap(&text->str_array[j], &text->str_array[j+1]);
            }
        }
    }
}

// Меняем местами два указателя на строки
void swap(char* str1, char* str2, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        char tmp = *(str1 + i);
        *(str1 + i) = *(str2 + i);
        *(str2 + i) = tmp;
    }
}