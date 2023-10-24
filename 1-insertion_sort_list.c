#include "sort.h"

/**
 * insertion_sort_list - a function that sorts a linked list using
 * insertion sort algorithim and prints the list after every swap
 *
 * @list: the list to sort
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;
	listint_t *temp_prev = (*list)->prev;
	listint_t *temp_next = (*list)->next;

	if (list == NULL || current == NULL || *list == NULL)
		return;

	while (current)
	{
		temp_next = current->next;
		while (current->prev != NULL && (current->n < current->prev->n))
		{
			temp_prev = current->prev;
			current->prev = temp_prev->prev;

			if (temp_prev->prev)
				current->prev->next = current;
			else
				*list = current;
			temp_prev->next = current->next;
			if (temp_prev->next)
				temp_prev->next->prev = temp_prev;
			current->next = temp_prev;
			temp_prev->prev = current;
		}
		print_list(*list);
		current = temp_next;
	}
}
