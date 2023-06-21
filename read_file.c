#include "monty.h"

/**
 * read_file - reads the contents of a file
 * @argc: argument count
 * @argv: the command line arguments
 *
 * Return: the file descriptor
 */

FILE *read_file(int argc, char *argv[])
{
	FILE *fd;

	/* checking the number of arguments passed */
	if (argc > 2 || argc == 1)
	{
		fprint(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* open and read the file */
	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file <file>\n");
		exit(EXIT_FAILURE);
	}

	fclose(argv[1]);

	return (fd);
}
