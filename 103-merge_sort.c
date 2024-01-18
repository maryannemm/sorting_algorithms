#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two sub-arrays
 * @array: Original array
 * @left: Start index of the left sub-array
 * @mid: Middle index (end of left sub-array)
 * @right: End index of the right sub-array
 * @temp: Temporary array to store the merged result
 */
void merge(int *array, size_t left, size_t mid, size_t right, int *temp)
{
    size_t i, j, k;

    printf("Merging...\n[left]: ");
    print_array(array + left, mid - left);

    printf("[right]: ");
    print_array(array + mid, right - mid);

    i = left;
    j = mid;
    k = 0;

    while (i < mid && j < right)
    {
        if (array[i] <= array[j])
        {
            temp[k] = array[i];
            i++;
        }
        else
        {
            temp[k] = array[j];
            j++;
        }
        k++;
    }

    while (i < mid)
    {
        temp[k] = array[i];
        i++;
        k++;
    }

    while (j < right)
    {
        temp[k] = array[j];
        j++;
        k++;
    }

    for (i = 0, k = left; k < right; i++, k++)
    {
        array[k] = temp[i];
    }

    printf("[Done]: ");
    print_array(array + left, right - left);
}

/**
 * merge_sort_recursive - Recursive function for merge sort
 * @array: Array to be sorted
 * @left: Start index of the sub-array
 * @right: End index of the sub-array
 * @temp: Temporary array to store the merged result
 */
void merge_sort_recursive(int *array, size_t left, size_t right, int *temp)
{
    size_t mid;

    if (right - left > 1)
    {
        mid = (left + right) / 2;

        merge_sort_recursive(array, left, mid, temp);
        merge_sort_recursive(array, mid, right, temp);

        merge(array, left, mid, right, temp);
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
    int *temp;

    if (array == NULL || size < 2)
        return;

    temp = malloc(size * sizeof(int));
    if (temp == NULL)
        return;

    merge_sort_recursive(array, 0, size, temp);

    free(temp);
}

