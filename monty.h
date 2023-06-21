#ifndef MONTY_H
#define MONTY_H

/* the data structures we'll use for this project */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* declaring the global variables */
/**
 * struct var - the global variables for this project
 * @args: an array to store the commands
 * @file: the pointer to the monty file
 * @top: to keep count of the number of items in the stack or queue
 *
 * Description: the global variables needed for this project
 * for use in the main program
 */

typedef struct var
{
	char *args;
	FILE *file;
	int top;
} var_t

/* declaring the external variable for sharing in other source code files */
extern var_t var_s;

#include <stdio.h>
#include <stdlib.h>

stack_t *add_node(stack_t **head, int n);
FILE *read_file(int argc, char *argv[]);
void push(stack_t **head, unsigned int linenum);

#endif /* MONTY_H */
