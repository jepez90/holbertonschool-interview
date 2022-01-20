#include "lists.h"

/**
 * is_palindrome - check if an listint_t list is a palindromo.
 * @head: pointer to the head of the linked list.
 *
 * Return: 1 if the list is a palindromo, 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
	listint_t *current;
	int i = 0;

	if (!head || !(*head))
		return (1);

	current = *head;
	/* travel the list to found its length */
	while (current->next)
	{
		current = current->next;
		i++;
	}

	if ((*head)->n != current->n)
		return (0);

	i -= 2;
	current = (*head)->next;

	while (i > 0)
	{
		/* if current is diferent of node in index i */
		if (current->n != get_dnodeint_at_index(current, i)->n)
			return (0);
		current = current->next;
		i -= 2;
	}
	return (1);
}


/**
 * get_dnodeint_at_index - searcha the node with the gived index in the list.
 * @head: pointer to the head of the double linked list.
 * @index: node to be returned
 *
 * Return: node at index or NULL.
 */
listint_t *get_dnodeint_at_index(listint_t *head, unsigned int index)
{
	while (head)
	{
		if (index-- == 0)
			return (head);

		head = head->next;
	}

	return (NULL);
}
