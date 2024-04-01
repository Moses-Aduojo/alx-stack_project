#include "monty.h"

/**
 * execute_instruction - exuctute monty instructions
 * @line_num: instuction line number in athe monty file
 * @stack: stack upon which the instruction is executed
 * Return: void
 */
void execute_instruction(stack_t **stack, int line_num)
{
	instruction_t instructions[] = {
		{"push", &push},
		{"pall", &pall},
		{NULL, NULL}
	};
	int num_instructions = sizeof(instructions) / sizeof(instructions[0]);
	int i;

	for (i = 0; i < num_instructions && instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, tokens[0]) == 0)
		{
			instructions[i].f(stack, line_num);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, tokens[0]);
	exit(EXIT_FAILURE);
}
