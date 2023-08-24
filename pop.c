#include "monty.h"
/**
 * pop - functions removes the top element of a stack.
 * @stack: this is the head od the stack. It points to head
 * @line_number: The line number or instruction number
 *
 * return: return nothing.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    current = *stack;
    *stack = (*stack)->next;
    if (*stack != NULL)
        (*stack)->prev = NULL;
    free(current);
}

