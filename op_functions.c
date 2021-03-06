#include "monty.h"
/**
 * push -¨Push an element to the stack
 * @stack: pointer to top of stack
 * @line_number: unused
 */
void push(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *top;
	stack_t *new_node;

	top = *stack;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new_node->prev = NULL;
	new_node->n = token2;
	new_node->next = *stack;

	if (*stack == NULL)
	{
		top->prev = new_node;
	}
	*stack = new_node;
}


/**
 * pall - prints all the values on the stack
 * @stack: pointer to list stack
 * @line_number: unused variable
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}


/**
 * pint - prints the value at the top of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", top->n);
}


/**
 * pop - removes the top element of the stack.
 * @stack: Pointer to the stack
 * @line_number: Line number of file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = top->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(top);
}
