#include "monty.h"

/**
 * pall - print all elements of a stack
 * @stack: pointer to the stack
 * @line_number: instruction line number in the monty file (unused)
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (line_number != 0)
	{
		;
	}
	if (*stack == NULL)
		return;

	while (current != NULL)
	{
	printf("%d\n", current->n);
	current = current->next;
	}
}
