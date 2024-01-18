#include "deck.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @deck: Pointer to the head of the list
 * @node1: First node to be swapped
 * @node2: Second node to be swapped
 */
void swap_nodes(deck_node_t **deck, deck_node_t *node1, deck_node_t *node2)
{
    if (node1->prev)
        node1->prev->next = node2;
    else
        *deck = node2;

    if (node2->next)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;

    node1->prev = node2;
    node2->next = node1;
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    int swapped;
    deck_node_t *ptr1 = NULL;
    deck_node_t *lptr = NULL;

    /* Check for empty or single card deck */
    if (*deck == NULL || (*deck)->next == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = *deck;

        while (ptr1->next != lptr)
        {
            if (ptr1->card->kind > ptr1->next->card->kind || 
               (ptr1->card->kind == ptr1->next->card->kind && 
                strcmp(ptr1->card->value, ptr1->next->card->value) > 0))
            {
                swap_nodes(deck, ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

