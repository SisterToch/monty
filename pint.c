#include "monty.h"
/**
 * pint - prints the top element in a stack
 * @stack: the head of the stack
 * @line_number: the line number or the instruction
 * number used for handling errors
 * return: returns nothing.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
