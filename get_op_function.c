#include "monty.h"
/**
 * get_op_function - This function select the function to exec.
 * @str: Argument operator passed
 * @line: Line number in the file
 * Return: None
 **/
void (*get_op_function(char *str, unsigned int line))(stack_t **, unsigned int)
{
	int i = 0;

	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	while(i < 7)
	{
		if (strcmp(str, ops[i].opcode) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknow instruction %s\n", line, str);
	exit(EXIT_FAILURE);
}

/**
 * parse_tok - parse arguments for opcode
 * @str: argument
 * Return: token
 */
char **parse_tok(char *str)
{
	char **token;
	char *delim = "\n\t ";
	int i;

	token = malloc(sizeof(char *) * 3);
	if (token == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token[0] = strtok(str, delim);

	for (i = 1; token != NULL && i < 2; i++)
	{
		token[i] = strtok(NULL, delim);
	}
	token[i] = NULL;
	return (token);
}
