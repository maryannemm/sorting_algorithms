#include "sort.h"

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order
 *                      using the Cocktail Shaker sort algorithm
 * @list: Pointer to the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *current;
    int swapped;

    if (list == NULL || *list == NULL)
        return;

    do {
        swapped = 0;
        for (current = *list; current->next != NULL; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, current, current->next);
                swapped = 1;
                print_list(*list);
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        for (; current->prev != NULL; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, current->prev, current);
                swapped = 1;
                print_list(*list);
            }
        }
    } while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the doubly linked list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    if (list == NULL || *list == NULL || node1 == NULL || node2 == NULL)
        return;

    if (node1->prev != NULL)
        node1->prev->next = node2;

    if (node2->next != NULL)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;
    node1->prev = node2;
    node2->next = node1;

    if (*list == node1)
        *list = node2;
}

