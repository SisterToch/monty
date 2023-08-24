#include "monty.h"
/**
 * push - functin ads nodes to the stack
 *
 * @stack: pints to the head of a stck
 * @value: the value of the node
 * @number: this is the line number or instructin
 * number for taargeting errors
 * return: nothing.
**/
		

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
