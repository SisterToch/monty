#include "monty.h"

stack_t *stack = NULL;

int main(int argc, char *argv[])
{
	char *filename, *token;
	FILE *monty_file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number;
	int value;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];
	monty_file = fopen(filename, "r");
	if (monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	line_number = 0;

	while ((read = getline(&line, &len, monty_file)) != -1)
	{
		line_number++;

        /*Tokenize the line to separate the command and its argument (if any)*/
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
        /*Add more opcode handlers here as needed*/
        else
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
            exit(EXIT_FAILURE);
        }
    }

    /*Close the file and free allocated memory*/
    free_stack(stack);
	free(line);
	fclose(monty_file);

    return EXIT_SUCCESS;
}
