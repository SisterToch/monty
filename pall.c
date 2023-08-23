#include "monty.h"
/**
 * c_pall - prints the stack
 * @head: the head of the stack
 * @number: acts like a counter (unused)
 * Return: nothing
*/

void c_pall(stack_t **stack, unsigned int number)
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
