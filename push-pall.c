#include "monty.h"
/**
 * push - adds element to the stack
 * @new_node: next node 
 * @stack- pointer to curent node
 */

int data;
struct node *next;

void push(int value)
{
	/*alocate memory to the new node*/
	struct_t *new_node = malloc(sizeof(struct_t));
	struct_t *stack = malloc(sizeof(struct_t));
	(void) new_node, (void) value;

	/*check if the stack is full*/
	if(stack == NULL )
	{
		
		exit(EXIT_FAILURE);
	}
	else
	{
		/*set node data*/
		stack->data = data;
		stack->next = next;

		/*push new node on to the stake*/
		new_node = stack;
	}
}

/**
 * pall - prints all elements
 * new_node: pointer to the next node
 */
void pall(void)
{
	struct_t *new_node = malloc(sizeof(struct_t));
	/*print all values of the stack*/
	while (new_node != NULL)
	{
		printf("%d\n", new_node->data);
		new_node = new_node->next;
	}
}

