#include "sort.h"

/**
 * swap_nodes - swap the nodes
 *@list: A pointer to the head of a doubly-linked list
 *@node1: A pointer to the tail of the doubly-linked list.
 *@node2: A pointer to the current swapping node of the cocktail shaker
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *prev1 = node1->prev;
	listint_t *next2 = node2->next;

	if (prev1)
		prev1->next = node2;
	else
		*list = node2;
	if (next2)
		next2->prev = node1;

	node2->prev = prev1;
	node2->next = node1;
	node1->prev = node2;
	node1->next = next2;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                     in ascending order using Cocktail Shaker Sort.
 * @list: Double pointer to the head of the linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *p1, *p2, *end = NULL;

	if (list == NULL || *list == NULL)
		return;
	do {
		swapped = 0;
		p1 = *list;
		while (p1->next != end)
		{
			if (p1->n > p1->next->n)
			{
				swap_nodes(list, p1, p1->next);
				print_list(*list);
				swapped = 1;
			}
			else
				p1 = p1->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		p2 = p1;
		end = p1;

		while (p2->prev != NULL)
		{
			if (p2->n < p2->prev->n)
			{
				swap_nodes(list, p2->prev, p2);
				print_list(*list);
				swapped = 1;
			}
			else
				p2 = p2->prev;
		}
	} while (swapped);
}
