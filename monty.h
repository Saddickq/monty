#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
/**
 * struct insert_s - info about exits and value for push
 * @push_number: the value for push opcode
 * @error: the exit value of the program
 */
typedef struct insert_s
{
	int push_number;
	int error;
} insert_t;

extern insert_t global_msg;

#define DELIM " \t\n\r"
FILE *open_file(char *file);
char **tokenise_line(char *line);
void process_line(char *line, stack_t **head, unsigned int line_number);
void operate(char *opcode, stack_t **head, unsigned int line_number);
void print_st(stack_t **head, unsigned int line_number);
void pop_st(stack_t **head, unsigned int line_number);
void push_st(stack_t **head, unsigned int line_number);
void take_first(stack_t **head, unsigned int line_number);
void add_st(stack_t **head, unsigned int line_number);
void swap_st(stack_t **head, unsigned int line_number);
void free_stack(stack_t *head);
#endif
