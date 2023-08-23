#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @value: the value of the node
 * @number: acts as a counter
**/
		
/*Function to push an element onto the stack */

void push(stack_t **stack, int value, unsigned int number)
{
	stack_t *new_node;

	(void)number;
	new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}
