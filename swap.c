#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: current line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	
	int value;
	stack_t *temp = *stack;
	if (!stack)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = temp->n;
	temp = temp->next;
	temp->next->n = value;
}

/**
 * nop - doesn't do anything
 * @stack: pointer to the stack
 * @line_number: current line number
 **/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
