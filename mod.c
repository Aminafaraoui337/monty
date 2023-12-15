#include "monty.h"

/**
 * mod - Adds the top two elements of the stack.
 * @stack: Pointer to top node of the stack.
 * @cmp: Interger.
 */
void mod(stack_t **stack, unsigned int cmp)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		moreErr(8, cmp, "mod");


	if ((*stack)->n == 0)
		moreErr(9, cmp);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
