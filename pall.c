#include "monty.h"
/**
 * f_pall - prints the stack
 * @head: head
 * @cmp: no used
 * Return: no return
*/
void f_pall(stack_t **head, unsigned int cmp)
{
	stack_t *h;
	(void)cmp;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
