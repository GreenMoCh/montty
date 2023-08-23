#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 *
 * @stack: ptr to a ptr to the top of the stack
 * @line_number: line number in the file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
