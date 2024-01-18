#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * bitonic_merge - Merges two subarrays in bitonic order
 * @array: Array to be sorted
 * @low: Starting index of the first subarray
 * @count: Size of the subarrays to be merged
 * @dir: Direction of the merge (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;
        size_t i;

        for (i = low; i < low + k; i++)
        {
            if ((array[i] > array[i + k]) == dir)
                swap(&array[i], &array[i + k]);
        }

        bitonic_merge(array, low, k, dir);
        bitonic_merge(array, low + k, k, dir);
    }
}

/**
 * bitonic_sort_recursive - Recursive function for bitonic sort
 * @array: Array to be sorted
 * @low: Starting index of the subarray
 * @count: Size of the subarray
 * @dir: Direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;

        bitonic_sort_recursive(array, low, k, 1);
        bitonic_sort_recursive(array, low + k, k, 0);

        bitonic_merge(array, low, count, dir);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2 || (size & (size - 1)) != 0)
        return;

    bitonic_sort_recursive(array, 0, size, 1);
}

