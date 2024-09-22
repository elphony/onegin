#include "qsort.h"

void debug_output(int orig_left, int orig_right, int l, int r, String* pivot, String* array) {

    for (int i = 0; i < orig_right - orig_left + 1; ++i) {
        if (i + orig_left + array == pivot)
            printf("[p->");
        else if (i == l)
            printf("[l->");
        else if (i == r)
            printf("[r->");
        else
            printf("[   ");
        
        printf("%2d] %s\n", i, array[orig_left + i].str);
    }
    printf("========\n");
}

#define HELP debug_output(l_hold, r_hold, left, right, pivot, array);

void q_sort(void* array, size_t left, size_t right, size_t size, compare_func comparator)
{
    if (left >= right)
        return;

    char* pivot = (char*)array + left * size; 
    size_t l_hold = left; 
    size_t r_hold = right;

    //HELP;

    while (left < right) 
    {

        //printf("===============WHILE STARTED==============\n");
        while ((comparator((char*)array + right * size, pivot) > 0) && (left < right))
            right--; 
        //HELP;

        if (left != right) 
        {
            if (pivot == (char*)array + left * size)
                pivot = (char*)array + right * size;
            else if (pivot == (char*)array + right * size)
                pivot = (char*)array + left * size;
            
            swap((char*)array + left * size, (char*)array + right * size, size);
            left++;
        }
        //HELP;


        while ((comparator((char*)array + left * size, pivot) < 0) && (left < right))
            left++; 
        //HELP;

        if (left != right) 
        {
            if (pivot == (char*)array + left * size)
                pivot = (char*)array + right * size;
            else if (pivot == (char*)array + right * size)
                pivot = (char*)array + left * size;

            swap((char*)array + right * size, (char*)array + left * size, size);
            right--; 
        }
        //HELP;

    }
    //printf("===============================STAGE ENDED============================\n");

    size_t index = (pivot - (char*)array)/size; 
    left = l_hold;
    right = r_hold;

    if (left < index) 
        q_sort(array, left, index - 1, size, comparator);
    if (right > index)
        q_sort(array, index + 1, right, size, comparator);
}