#include "monty.h"
/**
 * pall - prints the stack
 * @stack: the head of the stack
 * @number: this is the line number or the instruction number
 * Return: nothing
*/

void pall(stack_t **stack, unsigned int number)
{
	stack_t *current;
	(void)number; /* this parameter not used */

	if (*stack != NULL)
	{
		current = *stack;
		while (current != NULL)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
}
