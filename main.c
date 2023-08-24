#include "monty.h"
/**
 * main - This is the foundation of the code, it creates
 * a fulcum that has embedded in it, functions for
 * interpreting byte code and implementing them.
 * @argc: this is the number of the argument
 * @argv: the command line arguments itself
 * return: exits the program if done
 */
stack_t *stack = NULL;

int main(int argc, char *argv[])
{
	char *file_name, *token;
	FILE *monty_file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number;
	int value;

/*if the argument is just one, there is an error. should b 2*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_name = argv[1];
	monty_file = fopen(file_name, "r"); /*open d monty file*/
	if (monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	line_number = 0;

	while ((read = getline(&line, &len, monty_file)) != -1)
	{
		line_number++;

        /*Tokenize the line to separate the comnand)*/
		token = strtok(line, " \t\n");
		if (token == NULL)
			continue;

		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, " \t\n");
			if (token == NULL)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			value = atoi(token);
			if (value == 0 && *token != '0')
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			push(&stack, value, line_number);
		}
        else if (strcmp(token, "pall") == 0)
        {
            pall(&stack, line_number);
        }
	else if (strcmp(token, "pint") == 0)
	{
		pint(&stack, line_number);
	}
	else if (strcmp(token, "pop") == 0)
	{
		pop(&stack, line_number);
	}
	else if (strcmp(token, "swap") == 0)
	{
		swap(&stack, line_number);
	}
	else if (strcmp(token, "add") == 0)
	{
		add(&stack, line_number);
	}
	else if (strcmp(token, "nop") == 0)
	{
		nop(&stack, line_number);
	}
/*above is used to include the opcodes*/
        else
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
            exit(EXIT_FAILURE);
        }
    }

/*i used here to close the file and free the allocated memory when the file exits*/
	free_stackmemory(stack);
	free(line);
	fclose(monty_file);

	return EXIT_SUCCESS;
}
