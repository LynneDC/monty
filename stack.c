#define _POSIX_C_SOURCE 200890L
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

int main(int argc, char **argv)
{
FILE *fp;
stack_t *stack = NULL;
char *line = NULL;
size_t len = 0;
ssize_t nread;
unsigned int line_number = 0;
char *opcode = strtok(line, " \n");
char *arg = strtok(NULL, " \n");
/*int n = atoi(arg);*/

if (argc != 2)
{
fprintf(stderr, "Usage: monty file\n");
exit(EXIT_FAILURE);
}

fp = fopen(argv[1], "r");
if (fp == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
nread = getline(&line, &len, fp);
while (nread != -1)
{
line_number++;
opcode = strtok(line, " \n");
if (opcode == NULL || opcode[0] == '#')
continue;

if (strcmp(opcode, "push") == 0)
{
arg = strtok(NULL, " \n");
if (arg == NULL)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
/*n = atoi(arg);*/
push(&stack, line_number);
}
else if (strcmp(opcode, "pall") == 0)
{
pall_stack(stack, line_number);
}
else if (strcmp(opcode, "pint") == 0)
{
pint(&stack, line_number);
}
else if (strcmp(opcode, "pop") == 0)
{
pop(&stack, line_number);
}
else if (strcmp(opcode, "swap") == 0)
{
swap(&stack, line_number);
}
else if (strcmp(opcode, "add") == 0)
{
add_node(&stack, line_number);
}
else if (strcmp(opcode, "nop") == 0)
{
nop(&stack, line_number);
}
else
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
exit(EXIT_FAILURE);
}
}

free(line);
fclose(fp);
return 0;
}
