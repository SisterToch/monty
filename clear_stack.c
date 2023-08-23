#include "monty.h"
/*
*/

void clear_stack(stack_t **stack)
{
    stack_t *current = *stack;
    while (current != NULL)
    {
        *stack = current->next;
        free(current);
        current = *stack;
    }
}
