#include "monty.h"

/**
 * free_stack - frees a stack
 *
 * @stack: ptr to the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while(stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
