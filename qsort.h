#ifndef QSORT_H
#define QSORT_H

#include "input.h"
#include "compare.h"

void q_sort(void* array, size_t left, size_t right, size_t size, compare_func comparator);

void swap(char* str1, char* str2, size_t size);

#endif // QSORT_H