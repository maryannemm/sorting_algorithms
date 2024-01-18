#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                       using the Insertion sort algorithm.
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current;
    listint_t *temp;

    current = (*list)->next;

    while (current != NULL)
    {
        temp = current->next;

        while (current->prev != NULL && current->n < current->prev->n)
        {
            if (current->next != NULL)
                current->next->prev = current->prev;

            current->prev->next = current->next;
            current->next = current->prev;
            current->prev = current->prev->prev;
            current->next->prev = current;

            /* Print list after each swap */
            print_list(*list);
        }

        current = temp;
    }
}

