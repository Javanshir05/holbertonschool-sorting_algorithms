#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		next = current->next;
		insert = current->prev;

		while (insert && current->n < insert->n)
		{
			/* Detach current node */
			insert->next = current->next;
			if (current->next)
				current->next->prev = insert;

			/* Move current before insert */
			current->prev = insert->prev;
			current->next = insert;

			if (insert->prev)
				insert->prev->next = current;
			else
				*list = current;

			insert->prev = current;

			print_list(*list);
			insert = current->prev;
		}
		current = next;
	}
}
