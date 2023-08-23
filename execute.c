#include "monty.h"

/**
 * execute - Execute the opcode specified in the line
 * @content: Line content from the file
 * @stack: Pointer to the stack
 * @counter: Line number
 * @file: Pointer to the file being processed
 *
 * Return: 0 on success, 1 on failure
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	char *opcode = strtok(content, " \n\t");
	char *arg;
	int value;

	if (opcode == NULL || opcode[0] == '#')
		return (0);

	if (strcmp(opcode, "push") == 0)
	{
		arg = strtok(NULL, " \n\t");
		if (arg == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(file);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
		value = atoi(arg);
		push(stack, value);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, counter);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, counter);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap(stack, counter);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add(stack, counter);
	}
	else if (strcmp(opcode, "nop") == 0)
	{
		nop(stack, counter);
	}
	return (0);
}
