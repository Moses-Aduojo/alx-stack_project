#include "monty.h"

char *tokens[2];

/**
 * main - Entry point of the Monty interpreter program
 * @argc: Argument count
 * @argv: Argument vector (command-line arguments)
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	stack_t *stack = NULL;
	int line_num = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	exit(EXIT_FAILURE);
	}

	parse_and_execute_instructions(fp, &stack, &line_num);

	fclose(fp);
	free_stack(stack);

	return (0);
}

/**
 * parse_and_execute_instructions - Parse file and execute instructions
 * @fp: File pointer
 * @stack: Pointer to the stack
 * @line_num: Pointer to the line number counter
 */
void parse_and_execute_instructions(FILE *fp, stack_t **stack, int *line_num)
{
	char buff[1024];

	while (fgets(buff, sizeof(buff), fp) != NULL)
	{
		parse_and_execute(buff, stack, line_num);
		(*line_num)++;
		tokens[0] = "";
		tokens[1] = "";
	}
}

/**
 * parse_and_execute - Parse an instruction line and execute it
 * @instruction_line: Line containing the instruction
 * @stack: Pointer to the stack
 * @line_num: Pointer to the current line number
 */
void parse_and_execute(char *instruction_line, stack_t **stack, int *line_num)
{
	char *instruction_token;
	int i = 0;

	instruction_token = strtok(instruction_line, " $\n\t\v");
	while (instruction_token != NULL && i < 2)
	{
		tokens[i++] = instruction_token;
		instruction_token = strtok(NULL, " $\n\t\v");
	}

	if (i == 1)
		tokens[i] = "";

	if (strcmp(tokens[0], "\0") != 0)
	execute_instruction(stack, *line_num);
}
