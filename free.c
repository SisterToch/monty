#include "monty.h"
/**
 * free_stack - function frees memory when program
 * exits.
 * @stack: the stack to be freed
 * return: nothing
*/
void free_stackmemory(stack_t *stack)
{
	stack_t *current;

	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}
