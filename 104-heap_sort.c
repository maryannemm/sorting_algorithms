#include "sort.h"

/**
 * sift_down - Fixes the heap property in a subtree
 * @array: Array representing the heap
 * @start: Index of the root of the subtree
 * @end: Index of the last element in the subtree
 * @total_size: Total size of the heap
 */
void sift_down(int *array, size_t start, size_t end, size_t total_size)
{
    size_t root = start;

    while (2 * root + 1 <= end)
    {
        size_t child = 2 * root + 1;
        size_t swap = root;

        if (array[swap] < array[child])
            swap = child;

        if (child + 1 <= end && array[swap] < array[child + 1])
            swap = child + 1;

        if (swap != root)
        {
            int temp = array[root];
            array[root] = array[swap];
            array[swap] = temp;
            print_array(array, total_size);
            root = swap;
        }
        else
        {
            break;
        }
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    size_t i;
    size_t end;

    if (array == NULL || size < 2)
        return;

    i = size / 2;
    while (i > 0)
    {
        i--;
        sift_down(array, i, size - 1, size);
    }

    end = size - 1;
    while (end > 0)
    {
        int temp = array[end];
        array[end] = array[0];
        array[0] = temp;
        print_array(array, size);
        end--;
        sift_down(array, 0, end, size);
    }
}

