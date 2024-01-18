#include "sort.h"
#include <stdio.h>

/**
 * hoare_partition - Implements Hoare partition scheme for quicksort
 * @array: Array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: Size of the array
 *
 * Return: Index of the pivot after partitioning
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[low];
    int i = low - 1;
    int j = high + 1;
    int temp;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        /* Swap array[i] and array[j] */
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;

        /* Print array after each swap */
        printf("Swapping: ");
        print_array(array, size);
    }
}

/**
 * quick_sort_recursive - Implements the recursive part of quicksort
 * @array: Array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot = hoare_partition(array, low, high, size);

        /* Recursively sort the sub-arrays */
        quick_sort_recursive(array, low, pivot, size);
        quick_sort_recursive(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * using the Quick sort algorithm with Hoare partition scheme
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Initial call to the recursive quicksort function */
    quick_sort_recursive(array, 0, size - 1, size);
}

