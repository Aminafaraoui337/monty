#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void openFile(char *file_name);
int parseLine(char *buffer, int line_number, int format);
void readFile(FILE *);
int len_chars(FILE *);
void findFunc(char *, char *, int, int);

/*Stack operations*/
stack_t *create_node(int n);
void free(void);
void pstack(stack_t **, unsigned int);
void add_stack(stack_t **, unsigned int);
void add_queue(stack_t **, unsigned int);

void callFun(op_func, char *, char *, int, int);

void print_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);

/*Math operations with nodes*/
void add(stack_t **, unsigned int);
void sub(stack_t **, unsigned int);
void div(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);

/*String operations*/
void pchar(stack_t **, unsigned int);
void pstring(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

/*Error hanlding*/
void error(int error_code, ...);
void moreErr(int error_code, ...);
void stringErr(int error_code, ...);
void rotr(stack_t **, unsigned int);

#endif
