#include "qsort.h"

void q_sort(void* array, size_t left, size_t right, size_t size, compare_func comparator)
{
    if (left >= right)
        return;

    char* pivot = (char*)array + left * size; 
    size_t l_hold = left; 
    size_t r_hold = right;

    while (left < right) 
    {

        while ((comparator((char*)array + right * size, pivot) > 0) && (left < right))
            right--; 

        if (left != right) 
        {
            if (pivot == (char*)array + left * size)
                pivot = (char*)array + right * size;
            else if (pivot == (char*)array + right * size)
                pivot = (char*)array + left * size;
            
            swap((char*)array + left * size, (char*)array + right * size, size);
            left++;
        }

        while ((comparator((char*)array + left * size, pivot) < 0) && (left < right))
            left++; 

        if (left != right) 
        {
            if (pivot == (char*)array + left * size)
                pivot = (char*)array + right * size;
            else if (pivot == (char*)array + right * size)
                pivot = (char*)array + left * size;

            swap((char*)array + right * size, (char*)array + left * size, size);
            right--; 
        }

    }

    size_t index = (pivot - (char*)array)/size; 
    left = l_hold;
    right = r_hold;

    if (left < index) 
        q_sort(array, left, index - 1, size, comparator);
    if (right > index)
        q_sort(array, index + 1, right, size, comparator);
}

void swap(char* str1, char* str2, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        char tmp = *(str1 + i);
        *(str1 + i) = *(str2 + i);
        *(str2 + i) = tmp;
    }
}