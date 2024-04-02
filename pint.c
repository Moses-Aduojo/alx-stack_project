#include "monty.h"

/**
 * pint - print the top element of the stack
 * @stack: pointer to the head of the stack
 * @line_number: instruction line number in the monty file
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (temp->prev != NULL)
	{
		while (temp->prev != NULL)
		{
			temp = temp->prev;
		}
	}
	else
		printf("%d\n", temp->n);

}
