#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *		using the insertion sort algorithm
 * @list: A pointer to the head of a doubly-linked list of integers
 *
 * Description: Prints the list after each swap.
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *head, *previous, *prev_inner, *current_inner;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	previous = *list;
	current = (*list)->next;
	head = *list;

	while (current)
	{
		current_inner = current;
		prev_inner = previous;

		while (prev_inner && prev_inner->n > current_inner->n)
		{
			if (prev_inner->prev == NULL)
				head = current_inner;

			if (current_inner->next)
				current_inner->next->prev = prev_inner;

			if (prev_inner->prev)
				prev_inner->prev->next = current_inner;

			current_inner->prev = prev_inner->prev;
			prev_inner->next = current_inner->next;
			current_inner->next = prev_inner;
			prev_inner->prev = current_inner;

			prev_inner = current_inner->prev;
			print_list(head);
		}
		previous = current;
		current = current->next;
	}
	*list = head;
}
