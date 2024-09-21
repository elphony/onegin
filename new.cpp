#include <stdlib.h>
#include <stdio.h>

#include "qsort.h"
#include "sort.h"

int main() {
    int right = 0;
    int left = 5;
    char* numbers[left] = {"dddddddddd", "aaaa", "vvvv", "efwfw", "sfgsdfgves"};

    q_sort(numbers, right, left-1, sizeof(char*), &compare_str, FORWARD);

    for (int i = 0; i < left; ++i) {
        printf("%s\n", numbers[i]);
    }
    printf("\n");
}