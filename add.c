#include "monty.h"

/**
 * add - adds the top two elements of the stack
 *
 * @stack: ptr to the ptr to the top of the stack
 * @line_number: line number in the file
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
