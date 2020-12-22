#include "monty.h"
/**
 * main - Interpret of monty file
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: Value 0 or EXIT FAILURE
 */
int main(int argc, char *argv[])
{
	char *monty_file;

	monty_file = argv[1];
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(monty_file);
	return (0);
}

/**
 * open_file - Open a monty files
 * @filename: Name if monty file
 */
void open_file(char *filename)
{
	char *line_buffer = NULL;
	size_t size_l_b = 0;
	int line_count = 1;
	ssize_t line_size;
	FILE *fd;

	fd = fopen(filename, "r");
	if (filename == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	line_size = getline(&line_buffer, &size_l_b, fd);

	while (line_size > 0)
	{
		line_count++;
		line_size = getline(&line_buffer, &size_l_b, fd);
	}
	free(line_buffer);
	line_buffer = NULL;

	fclose(fd);
}
