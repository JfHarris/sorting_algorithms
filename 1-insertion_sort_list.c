#include "sort.h"

/**
 * insertion_sort_list - sorts list in ascending order using insertion sort
 *@list: doubliy linked list
 *
 * Return: Always 0
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *tmp;
	listint_t *tmp1;

	if (list != NULL || *list != NULL)
	{
		current = *list;
		tmp = current->next;
		if (tmp == NULL)
			return;
		while (tmp != NULL)
		{
			if (current->prev != NULL && current->n > tmp->n)
			{
				if (current->prev->n < tmp->n)
					break;
				current = current->prev;
			}
			tmp1 = current;
			current = tmp;
			tmp = tmp1;
			tmp = current->next;
			print_list(*list);
		}
		if (current->next != NULL)
			current = current->next;
		tmp = current->next;
	}
}
