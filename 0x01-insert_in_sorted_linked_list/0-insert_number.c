#include "lists.h"

/**
 * insert_node - insert a node with the specified value in a sorted simple
 * linked list
 *
 * @head: pointer to the head of rhe linked list
 * @number: integer to be inserted in the sorted list
 *
 * Return: pointer to the new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *head_copy;
	listint_t *new_node;

	/* validate data */
	if (head == NULL)
	{
		return (NULL);
	}

	/* make a copy of the head */
	head_copy = *head;

	/* create a new node */
	new_node = malloc(sizeof(listint_t) * 1);
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->next = NULL;
	new_node->n = number;

	if (head_copy == NULL || head_copy->n > number)
	{
		/* inserts the node if it is the first */
		new_node->next = head_copy;
		*head = new_node;
	}
	else
	{
		/* inserts the node if it in another case */
		while (head_copy->next != NULL && head_copy->next->n < number)
		{
			head_copy = head_copy->next;
		}

		new_node->next = head_copy->next;
		head_copy->next = new_node;
	}

	return (new_node);
}
