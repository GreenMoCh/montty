#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
void free_stack(stack_t *stack);
#define MAX_LINE_LENGTH 1024

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: array of arguments
 *
 * Return: Exit_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	FILE *file = NULL;
	stack_t *stack = NULL;
	char line[MAX_LINE_LENGTH];
	unsigned int line_number = 1;
	int ret;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file))
	{
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';

		ret = execute(line, &stack, line_number, file);
		if (ret == 1)
		{
			fprintf(stderr, "L%d: unknown instruction\n", line_number);
			fclose(file);
			free_stack(stack);
			return (EXIT_FAILURE);
		}
		line_number++;
	}
	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
