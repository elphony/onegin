#ifndef QSORT_H
#define QSORT_H

#include "input.h"
#include "sort.h"

void q_sort(String* array, int left, int right, compare_func comparator, Mode option);

#endif // QSORT_H