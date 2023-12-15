#include "monty.h"
/**
  *sub- sustration
  *@head: head
  *@cmp: nombre lignes
  *Return: no return
 */
void sub(stack_t **head, unsigned int cmp)
{
	stack_t *que;
	int sust, nd;

	que = *head;
	for (nd = 0; que != NULL; nd++)
		que = que->next;
	if (nd < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", cmp);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	que = *head;
	sust = que->next->n - que->n;
	que->next->n = sust;
	*head = que->next;
	free(que);
}
