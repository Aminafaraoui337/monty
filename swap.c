#include "monty.h"
/**
 * swap - adds the top 2 elements of the stack.
 * @head: head
 * @cmp: nombre lignes
 * Return: no return
*/
void swap(stack_t **head, unsigned int cmp)
{
	stack_t *h;
	int lon = 0, que;

	h = *head;
	while (h)
	{
		h = h->next;
		lon++;
	}
	if (lon < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", cmp);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	que = h->n;
	h->n = h->next->n;
	h->next->n = que;
}
