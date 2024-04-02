#include "monty.h"

char *tokens[2];
/**
 * main - take a file containing monty instruction and run
 * @argc: argument count
 * argv: argement list. in this case file name
 * Return: 0 on sucess 1 otherwise
 */
int main(int argc, char *argv[])
{
	int line_num = 1;
	char buff[1024];
	char *instruction_token;
	FILE *fp;
	stack_t *stack = NULL;
	int i;

	if (argc != 2)
	{
		perror("USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buff, sizeof(buff), fp) != NULL)
	{
		instruction_token = strtok(buff, " $\n\t\v");
		i = 0;
		while(instruction_token != NULL)
		{
			if (i > 1)
				break;
			tokens[i] = instruction_token;
			instruction_token = strtok(NULL, " $\n\t\v");
			i++;
		}
		if (i == 1)
			tokens[i] = "";
		if (strcmp(tokens[0], "\0") != 0)
			execute_instruction(&stack, line_num);
		tokens[0] = "";
		tokens[1] = "";
		line_num++;
	}
	return (0);
}

