#include "monty.h"

/**
* push - adds a new node at the end
* of a stack_t list
*
* @head: head of the list
* @n: value of the element
* Return: the address of the new element
*/
stack_t *push(stack_t **head, const int n)
{
stack_t *h;
stack_t *new;

new = malloc(sizeof(stack_t));
if (new == NULL)
return (NULL);

new->n = n;
new->next = NULL;

h = *head;

if (h != NULL)
{
while (h->next != NULL)
h = h->next;
h->next = new;
}
else
{
*head = new;
}

new->prev = h;

return (new);
}
