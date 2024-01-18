#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
    int max, *counting_array, *sorted_array;
    size_t i;

    if (array == NULL || size <= 1)
        return;

    /* Find the maximum value in the array */
    max = array[0];
    i = 1;
    while (i < size)
    {
        if (array[i] > max)
            max = array[i];
        i++;
    }

    /* Create counting array and initialize with zeros */
    counting_array = malloc((max + 1) * sizeof(int));
    if (counting_array == NULL)
        return;

    i = 0;
    while (i <= (size_t)max)
    {
        counting_array[i] = 0;
        i++;
    }

    /* Count occurrences of each element */
    i = 0;
    while (i < size)
    {
        counting_array[array[i]]++;
        i++;
    }

    /* Update counting array to store the position of each element */
    i = 1;
    while (i <= (size_t)max)
    {
        counting_array[i] += counting_array[i - 1];
        i++;
    }

    /* Create the sorted array using the counting array */
    sorted_array = malloc(size * sizeof(int));
    if (sorted_array == NULL)
    {
        free(counting_array);
        return;
    }

    i = 0;
    while (i < size)
    {
        sorted_array[counting_array[array[i]] - 1] = array[i];
        counting_array[array[i]]--;
        i++;
    }

    /* Copy the sorted array back to the original array */
    i = 0;
    while (i < size)
    {
        array[i] = sorted_array[i];
        i++;
    }

    /* Print counting array */
    printf("%d", counting_array[0]);
    i = 1;
    while (i <= (size_t)max)
    {
        printf(", %d", counting_array[i]);
        i++;
    }
    printf("\n");

    free(counting_array);
    free(sorted_array);
}

