#include "monty.h"

/**
 * swap - swap the top two elements of the stack
 *
 * @stack: ptr to the ptr to the top of the stack
 * @line_number: line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		second = (*stack)->next;

		first->next = second->next;
		if (second->next)
			second->next->prev = first;
		second->prev = NULL;
		second->next = first;
		first->prev = second;
		*stack = second;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
