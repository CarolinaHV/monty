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
	char *token = NULL;

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

	token = strtok(str, "\t\n ");

	while (i < 7)
	{
		token = (ops[i]).opcode;
		if (strcmp(str, token) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}
	return (0);
}
