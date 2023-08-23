#include "monty.h"
/**
 * add -this funtion adds the top two elements
 * present in the stack
 * @stack: points to the head of the stack.
 * @number: acts like a counter, telling the number
 * of the instructions given.
 */
void add(stack_t **stack, unsigned int number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, number);
}
