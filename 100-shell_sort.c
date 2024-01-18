#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 *              with the Knuth sequence
 * @array: Array to be sorted
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
    size_t gap, i, j;
    int temp;

    if (array == NULL || size < 2)
        return;

    /* Initialize the gap using the Knuth sequence */
    for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
        ;

    /* Start with the largest gap and work down to a gap of 1 */
    for (; gap > 0; gap /= 3)
    {
        /* Perform insertion sort for the current gap */
        for (i = gap; i < size; i++)
        {
            temp = array[i];
            /* Shift elements until the correct position is found */
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
            {
                array[j] = array[j - gap];
            }
            array[j] = temp;
            /* Print array after each iteration with a reduced gap */
            print_array(array, size);
        }
    }
}

