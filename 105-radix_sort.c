#include "sort.h"
#include <stdlib.h>

/**
 * getMax - Returns the maximum element from an array
 * @array: Array to find the maximum element from
 * @size: Size of the array
 * Return: The maximum element
 */
int getMax(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}

/**
 * countingSort - Sorts an array using counting sort based on the significant place
 * @array: Array to be sorted
 * @size: Size of the array
 * @exp: The current significant place (1, 10, 100, ...)
 */
void countingSort(int *array, size_t size, int exp)
{
    int *output, count[10] = {0};
    size_t i;

    output = malloc(size * sizeof(int));
    if (output == NULL)
        return;

    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; (int)i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max, exp;

    if (array == NULL || size < 2)
        return;

    max = getMax(array, size);

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(array, size, exp);
        print_array(array, size);
    }
}

