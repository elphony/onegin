#ifndef QSORT_H
#define QSORT_H

#include "input.h"
#include "sort.h"

void q_sort(void* array, size_t left, size_t right, size_t size, compare_func comparator);

#endif // QSORT_H