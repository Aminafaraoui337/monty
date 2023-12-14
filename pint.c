#include "monty.h"
/**
 * f_pint - prints the top
 * @head: head
 * @cmp: nombre lignes
 * Return: no return
*/
void f_pint(stack_t **head, unsigned int cmp)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", cmp);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
