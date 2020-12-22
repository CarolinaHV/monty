#include "monty.h"
/**
 * get_op_function - This function select the function to exec.
 * @str: Argument operator passed
 * @stack: Ponter to the stack
 * @line_number: Line number in the file
 * Return: None
 **/
void (*get_op_function(char *str))(stack_t **, unsigned int)
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

	while (i < 7)
	{
		if (strcmp(str, ops[i].opcode) == 0)
		{
			return (ops[i].f);
		}
		i++;
		if (str[0] == '#')
		{
			nop = ()
		}
		
	}
	return (0);
}


/**
 * parse - parse arguments for opcode
 * @str: argument
 * Return: token
 */
char parse(char *str)
{
	char *token = NULL;
	char *delim = "\n\t ";

	token = malloc(sizeof(char *));
	if (token == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(str, delim);

	while (token != NULL)
	{
		token = strtok(NULL, delim);
	}
	token = NULL;
	return (token);
}
