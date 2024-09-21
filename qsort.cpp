#include "qsort.h"

void q_sort(String* array, int left, int right, compare_func comparator, Mode option)
{
    if (left >= right)
        return;

    String* pivot; 
    int index;
    int l_hold = left; 
    int r_hold = right;

    pivot = (array + left);
    printf("pivot = %s\n\n", *(array + left));

    for (int i = 0; i < 8; ++i) {
        printf("%s\n", (array + i)->str);
    }

    left++;
    while (left < right) 
    {
        while ((comparator(&array[right], pivot, option) > 0) && (left < right))
            right--; 
        if (left != right) 
        {
            //printf("pivot = %s\n", )
            //String* pointer = &array[left];
            //pointer = &array[right];
            swap(array + left, array + right);
            left++; 
        }
        while ((comparator(&array[left], pivot, option) < 0) && (left < right))
            left++; 
        if (left != right) 
        {
            //String* pointer = &array[right];
            //pointer = &array[left]; 
            swap(array + right, array + left);
            right--; 
        }
    }

    printf("----------------------------------------------------------------------------------------------------------\n");

    // String* pointer = &array[left];
    // pointer = pivot;

    swap(array + left, pivot);


    index = left; 
    left = l_hold;
    right = r_hold;

    if (left < index) 
        q_sort(array, left, index - 1, comparator, option);
    if (right > index)
        q_sort(array, index + 1, right, comparator, option);
}