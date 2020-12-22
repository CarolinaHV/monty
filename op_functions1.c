#include "monty.h"
/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to top of stack
 * @line_number: Line number file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	stack_t *top = NULL;

	top = *stack;

	if (top != NULL && top->next != NULL)
	{
		tmp = top->next;
		top->prev = top->next;
		top->next = tmp->next;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}


/**
 * add - adds the top two elements of the stack
 * @stack: pointer to list stack
 * @line_number: line number file.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	top = *stack;
	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

}


/**
 * nop - doesn’t do anything
 * @stack: Not using
 * @line_number: Not using
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
