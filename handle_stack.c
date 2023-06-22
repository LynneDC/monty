#include "monty.h"

/**
 * pall_stack - prints all the elements of a
 * stack list
 *
 * @h: head of the list
 * Return: the number of nodes
 */
void pall_stack(const stack_t *h, int count)
{
	
	count = 0;
/*check the is the stack is not empty*/
	if (h != NULL)
	{	while (h->prev != NULL)
			h = h->prev;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}
	}
}


/**
 * pint-function inserts a new node at a given position
 * @head: pointer to the first node
 * @idx: index where new node will be added
 * @n: data to  to the new node
 *  Return: address ofnew node or NULL if it fails
 */

stack_t *pint(stack_t **head, unsigned int idx)
{
	int n = 0;
	unsigned int  i;
	stack_t *new;
	stack_t *temp = *head;

	new = malloc(sizeof(stack_t));
	if (!new || !head)
		return (NULL);
	new->n = n;
	new->next = NULL;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	for (i = 0; temp && i < idx; i++)
	{
		if (i == idx - 1)
		{
			new->next = temp->next;
			temp->next = new;
			return (new);
		}
		else
			temp = temp->next;
	}
	return (NULL);
}



/**
 * pop - deletes the node at top of a
 * stack
 *
 * @head: head of the list
 * @top: index of the new node
 * Return: 1 if it succeeded, -1 if it failed
 */
void pop(stack_t **head, unsigned int top)
{
	stack_t *h1;
	stack_t *h2;
	unsigned int i;

	h1 = *head;

	if (h1 != NULL)
		while (h1->prev != NULL)
			h1 = h1->prev;

	i = 0;

	while (h1 != NULL)
	{
		if (i == top)
		{
			if (i == 0)
			{
				*head = h1->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				h2->next = h1->next;

				if (h1->next != NULL)
					h1->next->prev = h2;
			}

			free(h1);

		}
		h2 = h1;
		h1 = h1->next;
		i++;
	}


}
