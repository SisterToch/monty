#include "monty.h"
/**
 * swap - function that swap the two top element of a stack
 *
 * @stack: this is a pinter to the head of stack.
 * @line_number: the line number ot instruction line
 * it is for errors
 *
 * return: returns nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int current;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = current;
}
