#include "monty.h"
/**
 * push_st - add a node at the beginning of the lists
 * @head: the ponter to the head node
 * @line_number: line of execution
 * Return: void
*/
void push_st(stack_t **head, unsigned int line_number)
{
	stack_t *new_node = NULL;

	(void) line_number;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		global_msg.error = EXIT_FAILURE;
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
/**
 * pop_st - delete the beginning of the lists
 * @head: the ponter to the head node
 * @line_number: the line of execution
 * Return: void
*/
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

/**
 * print_st - print all elements in the stack
 * @head: the ponter to the head node
 * @line_number: the line of execution
 * Return: void
*/
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
 * take_first - show the topmost element in the stack
 * @head: the ponter to the head node
 * @line_number: the line of execution
 * Return: void
 */
void take_first(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		global_msg.error = EXIT_FAILURE;
		return;
	}

	while ((*head)->prev != NULL)
	{
		*head = (*head)->prev;
	}
	printf("%d\n", (*head)->n);
}

/**
 * swap_st - swap the values of the two topmost elements
 * @head: the ponter to the head node
 * @line_number: the line of execution
 * Return: void
 */
void swap_st(stack_t **head, unsigned int line_number)
{
	stack_t *second = NULL;
	stack_t *first = NULL;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		global_msg.error = EXIT_FAILURE;
		return;
	}

	first = *head;
	second = (*head)->next;

	first->next = second->next;
	second->next = first;

	*head = second;
}
