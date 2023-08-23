#include "monty.h"

/**
 * pop - removes the top element of the stack
 *
 * @stack: ptr to a ptr to the top of the stack
 * @line_number: line number in the file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}
