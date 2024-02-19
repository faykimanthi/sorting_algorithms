#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a listint_t doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @node1: A pointer to the first node to swap.
 * @node2: The second node to swap.
 */
void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	listint_t *prev_node1 = (*node1)->prev;
	listint_t *next_node2 = node2->next;

	if (prev_node1)
	prev_node1->next = node2;
	else
	*head = node2;

	if (next_node2)
	next_node2->prev = *node1;

	(*node1)->prev = node2;
	node2->next = *node1;
	node2->prev = prev_node1;
	(*node1)->next = next_node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion_point, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = NULL;
	insertion_point = NULL;
	tmp = NULL;

	for (current = (*list)->next; current != NULL; current = tmp)
	{
		tmp = current->next;
		insertion_point = current->prev;

	while (insertion_point != NULL && current->n < insertion_point->n)
	{
		swap_nodes(list, &insertion_point, current);
		print_list((const listint_t *)*list);
	}
	}
}
