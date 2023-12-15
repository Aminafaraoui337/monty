#include "monty.h"


/**
 * add_stack - Adds a node to the stack.
 * @new: the new node.
 * @ln: counter.
 */
void add_stack(stack_t **new, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new == NULL || *new == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new;
		return;
	}
	tmp = head;
	head = *new;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * pstack - Adds a node to the stack.
 * @stack: head.
 * @cmp: counter.
 */
void pstack(stack_t **stack, unsigned int cmp)
{
	stack_t *tmp;
        (void)cmp;
        if (stack == NULL)
                exit(EXIT_FAILURE);
        tmp = *stack;
        while (tmp != NULL)
        {
                printf("%d\n", tmp->n);
                tmp = tmp->next;
        }
}

/**
 * pop_top - Adds a node to the stack.
 * @stack: head.
 * @cmp: counter.
 */
void pop_top(stack_t **stack, unsigned int cmp)
{
        stack_t *tmp;

        if (stack == NULL || *stack == NULL)
                moreErr(7, cmp);

        tmp = *stack;
        *stack = tmp->next;
        if (*stack != NULL)
                (*stack)->prev = NULL;
        free(tmp);
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: head.
 * @cmp: counter.
 */
void print_top(stack_t **stack, unsigned int cmp)
{
        if (stack == NULL || *stack == NULL)
                moreErr(6, cmp);
        printf("%d\n", (*stack)->n);
}
