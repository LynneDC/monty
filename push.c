#include "monty.h"

/**
 * push_int - puts an int to the top of a stack
 * @head
 * @h
 *
 * Return: Nothing
 */

void push_int(stack_t **head, unsigned int linenum)
{
	int i;

	/* checking if args is empty */
	if (var_s.args == NULL || var_s.args[0] == '-')
	{
		fprintf(stderr, "L%d: usage: push integer\n", linenum);
		exit(EXIT_FAILURE);
	}
	for (i = 0; var_s.args[i] != '\0'; i++)
	{
		if (var_s.args[i] > 57 || var_s.args[i] < 48)
		{
			fprintf(stderr, "L%d: usage: push integer\n", linenum);
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(var_s.args); /* converting string to int */
	add_node(head, n);
}
