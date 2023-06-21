#include "monty.h"

/**
 * add_node - this function adds a node at the start of a doubly linked list
 * @head: pointer to the first node
 * @n: the data to be added
 *
 * Return: the list
 */

stack_t *add_node(stack_t **head, int n)
{
	stack_t *temp, newNode; /* ptrs to traverse the list */

	newNode = (stack_t *)malloc(sizeof(stack_t)); /* allocating memory */
	newNode->n = n;
	newNode->prev = NULL;
	temp = *head;

	if (*head == NULL) /* list is empty */
	{
		newNode->next = NULL;
		*head = newNode;
		return (*head);
	}
	else
	{
		while (temp->prev != NULL)
			temp = temp->prev;
		temp->prev = newNode;
		newNode->next = temp;
	}

	*head = newNode;

	return (*head);
 }
