#include "monty.h"

/**
 * pchar - Prints the Ascii value.
 * @stack: head.
 * @cmp: counter.
 */
void pchar(stack_t **stack, unsigned int cmp)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		stringErr(11, cmp);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		stringErr(10, cmp);
	printf("%c\n", ascii);
}

/**
 * pstring - Prints a string.
 * @stack: head.
 * @cmp: counter.
 */
void pstring(stack_t **stack, __attribute__((unused))unsigned int cmp)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: head.
 * @cmp: count.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int cmp)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: head.
 * @cmp: counter.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int cmp)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
