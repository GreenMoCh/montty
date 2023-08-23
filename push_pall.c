#include "monty.h"

/**
 * push - pushes an element to the stack
 *
 * @stack: ptr to ptr to the top of the stack
 * @n: value to push into the stack
 */
void push(stack_t **stack, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - prints all value on the stack
 *
 * @stack: ptr to a ptr to the top of the stack
 */
void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
