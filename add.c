#include "monty.h"
/**
 * add -this function adds the top two elements
 * present in the stack
 * @stack: points to the head of the stack.
 * @line_number: line number or instruction number used for
 * error reporting
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
