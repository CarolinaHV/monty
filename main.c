#include "monty.h"
/**
 * open_file - Open a monty files
 * @filename: Name if monty file
 */
void open_file(char *filename)
{
	FILE *fd;
	size_t size_l_b = 0;
	int line_count = 1;
	stack_t *stack;
	char *line_buffer = NULL;
	char **token = NULL;


	fd = fopen(filename, "r");
	if (filename == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (getline(&line_buffer, &size_l_b, fd) != -1)
	{
		token = parse_tok(line_buffer);
		get_op_function(token[0], line_count)(&stack, line_count);
		line_count++;
		token2 = atoi(token[1]);
		free(token);
	}
	free(line_buffer);
	line_buffer = NULL;

	fclose(fd);
}

/**
 * main - Interpret of monty file
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: Value 0 or EXIT FAILURE
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	return (0);
}
