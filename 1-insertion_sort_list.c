#include "sort.h"

/**
 * insertion_sort_list - sorts given doubbly linked list is ascending order 
 * using insertion sort algorithm
 * @list: list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list;
	listint_t  *prev = NULL;
	listint_t *next = NULL;
	
	/* if list has 0 or 1 node, no sorting required*/
	if (*list == NULL || (*list)->next == NULL)
	{
		return;
	}

	current = (*list)->next;
	while (current)
	{
		next = current->next;
		prev = current->prev;
		while (prev && prev->n > current->n)
		{
			if (prev->prev)
			{
				prev->prev->next = current;
			}
			else
			{
				*list = current;
			}

			if (current->next)
			{
				current->next->prev = prev;
			}

			prev->next = current->next;
			current->prev = prev->prev;

			current->next = prev;
			prev->prev = current;

			print_list(*list);
			prev = current->prev;
		}

		current = next;
	}
}
