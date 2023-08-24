#include "monty.h"
/**
 * add -this funtion adds the top two elements
 * present in the stack
 * @stack: points to the head of the stack.
 * @line_number: acts like a counter, telling the number
 * of the instructions given.
 * return: returns nothing.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
/*add the value below top with the top valu and store in the below*/
	pop(stack, line_number);
} /*delete the top value*/
