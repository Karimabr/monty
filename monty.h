#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#define Buffsize 30

/**
 * struct stack_s - A doubly linked list representation of stack
 * @n: An integer
 * @prev: Pointer to previous element of the stack.
 * @next: Pointer to next element of the stack.
 * Description: Doubly linked list node structure for lifo & fifo.
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - The opcode and its function.
 * @opcode: Opcode.
 * @f: The function which handles the opcode.
 * Description: The opcode and its function.
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct glob_var - The golbal variable.
 * @file: file's name.
 * @buff: The getline buffer.
 * @tmp: The getline counter.
 * @dict: The instruction dictionary.
 * @head: A pointer to list.
 * @line_number: Stores file's current line.
 * @MODE: Program configuration stack or queue.
 */
typedef struct glob_var
{
	FILE *file;
	char *buff;
	size_t tmp;
	instruction_t *dict;
	stack_t *head;
	unsigned int line_number;
	int MODE;
} vars;


extern vars var;
int start_vars(vars *var);
instruction_t *create_instru();
int call_funct(vars *var, char *opcode);
void free_all(void);
int _isdigit(char *string);


void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);


void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divi(stack_t **stack, unsigned int line_number);


void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);


void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);


#endif
