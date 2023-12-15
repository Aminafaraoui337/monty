#include "monty.h"

/**
 * openFile - opens a file
 * @nf: the file name
 * Return: void
 */

void openFile(char *nf)
{
	FILE *fd = fopen(nf, "r");

	if (nf == NULL || fd == NULL)
		error(2, nf);

	readFile(fd);
	fclose(fd);
}


/**
 * readFile - reads a file
 * @fd: file descriptor
 * Return: void
 */

void readFile(FILE *fd)
{
	int cmp, format = 0;
	char *buff = NULL;
	size_t lon = 0;

	for (cmp = 1; getline(&buff, &lon, fd) != -1; cmp++)
	{
		format = parseLine(buff, cmp, format);
	}
	free(buff);
}


/**
 * parseLine - Separates each line into tokens to determine
 * @buff: line from the file
 * @cmp: counter
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack, 1 if queue.
 */

int parseLine(char *buff, int cmp, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buff == NULL)
		error(4);

	opcode = strtok(buff, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	findFunc(opcode, value, cmp, format);
	return (format);
}

/**
 * findFunc - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @cmp: counter
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void findFunc(char *opcode, char *value, int cmp, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_stack},
		{"pall", pstack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstring},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			callFunc(func_list[i].f, opcode, value, cmp, format);
			flag = 0;
		}
	}
	if (flag == 1)
		error(3, cmp, opcode);
}


/**
 * callFun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @opcode: the opcode.
 * @val: string.
 * @cmp: counter.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void callFun(op_func func, char *opcode, char *val, int cmp, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(opcode, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			error(5, cmp);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				error(5, cmp);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, cmp);
		if (format == 1)
			add_queue(&node, cmp);
	}
	else
		func(&head, cmp);
}
