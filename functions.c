#include "monty.h"

void push_st(stack_t **head, unsigned int line_number)
{
	stack_t *new_node = NULL;

	(void) line_number;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return;
	}

	new_node->n = global_msg.push_number;
	new_node->next = *head;
	new_node->prev = NULL;

	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}
	*head = new_node;
}

void pop_st(stack_t **head, unsigned int line_number)
{
	stack_t *current = NULL;

	(void) line_number;

	if (*head == NULL)
		return;

	current = *head;

	*head = current->next;
	if (*head != NULL)
	{
		current->next->prev = NULL;
	}
	free(current);
}


void print_st(stack_t **head, unsigned int line_number)
{
	int count = 0;
	stack_t *temp = NULL;

	(void) line_number;

	if (*head == NULL)
		return;

	temp = *head;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		count++;
		temp = temp->next;
	}
}
/**
 *
 * void take_first(stack_t **head, unsigned int line_number)
{
	(void) line_number;
}
void add_st(stack_t **head, unsigned int line_number)
{
	(void) line_number;
}
void swap_st(stack_t **head, unsigned int line_number)
{
	(void) line_number;
}*/
