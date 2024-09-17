#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

struct String {
    char* str;
    size_t len;
};

struct Text {
    String* str_array;
    size_t str_num;
};

int compare_str(String str1, String str2);
void sort_str(Text text);
void swap(char** pointer1, char** pointer2);
String input_file(char* name_file);
Text file_to_array(String file_str);

// если сразу после чтения приводить все буквы к одному регистру
// то потом при выводе текст будет неприятный
// а в каждом сравнении проверять регистр звучит как очень плохая идея (будет повторяться много раз)
// получается что надо сохранять регистры????? бред - много памяти и доп проверки при выводе

// функция вывода
// аргумент командной строки
// перейти на qsort -- указатль на функцию

int main() {
    char name_file[] = "test.txt"; 
    String file = input_file(name_file);
    Text onegin = file_to_array(file);

    //for (size_t i = 0; i < onegin.str_num; ++i) {
    //    printf("%s\n", onegin.str_array[i].str);
    //}
    
    sort_str(onegin);

    for (size_t i = 0; i < onegin.str_num; ++i) {
        printf("%s\n", onegin.str_array[i].str);
    }

    free(onegin.str_array);
    free(file.str);
}

String input_file(char* name_file) {
    FILE* f = fopen(name_file, "rb");
    assert(f != nullptr && "Error opening the file");

    String res = {};
    struct stat file_stat = {};
    
    fstat(fileno(f), &file_stat);
    assert(errno == 0 && "Information reading error");

    res.len = (size_t)file_stat.st_size;
    res.str = (char*)calloc(res.len + 1, sizeof(char));
    assert(res.str != nullptr && "Memory allocation error");

    size_t count = fread(res.str, sizeof(char), res.len, f);
    assert(count == res.len && "Error reading the file");

    res.str[res.len] = '\0';

    // for (size_t i = 0; i < res.len; i++) {
    //     printf("%c %d ", res.str[i], res.str[i]);
    // }

    fclose(f);

    return res; 
}

// получаем строку всего файла
// считаем количество строк по \n
// выделяем необходимое количество памяти на указатели
// снова идем по массиву и ищем строки по \r и \n
// каждую новую сохраняем в массив указателей вместе с длиной 
Text file_to_array(String file_str) {
    //size_t size_str = 0;
    //for (size_t i = 0; i < file_str.len; ++i) {
    //   printf("%c %d ", file_str.str[i], file_str.str[i]);
    //}
    //printf("\n------------------------------------------------------\n");

    Text res = {nullptr, 0};

    for (size_t i = 0; i < file_str.len; ++i) {
        //printf("%c ", file_str.str[i]);
        if (file_str.str[i] == '\n') {
            res.str_num++;
            file_str.str[i] = '\0';
        }
    }

    res.str_array = (String*)calloc(res.str_num + 1, sizeof(String));
    assert(res.str_array != nullptr && "Memory allocation error");

    size_t count_str = 0;

    res.str_array[0] = {file_str.str, 0};
    //fprintf(stderr, "%c in %zu\n", file_str.str[0], count_str);
    for (size_t i = 0; i < file_str.len-1; ++i) {
        //fprintf(stderr, "%c in %d\n", file_str.str[i], count_str);
        if (file_str.str[i] == '\0') {
            count_str++;
            //fprintf(stderr, "%c in %zu\n", file_str.str[i+1], count_str);
            res.str_array[count_str] = {file_str.str + i + 1, 0};
            //fprintf(stderr, "%d - ok\n", i);
        }
    }

    /*
    for (size_t i = 0; i < file_str.len-1; i++) {
        size_str++;
        if ((file_str.str[i] == '\r') || (file_str.str[i] == '\n')) {
            file_str.str[i] = '\0';
            res.str_array[count_str] = {file_str.str - size_str + 1, size_str};
            size_str = 0;
        }
    }
    */
    return res;
}

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

void swap(char** pointer1, char** pointer2) {
    char* new_pointer = *pointer1;
    *pointer1 = *pointer2;
    *pointer2 = new_pointer;
}