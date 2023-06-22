#include "monty.h"
/**
 * free_stack - free the memory used by stack_t
 * @head: the pointer to the head of the lists
 * Return: void
*/
void free_stack(stack_t *head)
{
	stack_t *temp = NULL;

	temp = head;
	while (temp != NULL)
	{
		head = head->next;
		free(temp);
		temp = head;
	}
}

/**
 * add_st - add the two topmost element in the stack
 * @head: the ponter to the head node
 * @line_number: the line of execution
 * Return: void
 */
void add_st(stack_t **head, unsigned int line_number)
{
	int first, second;
	int sum = 0;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		global_msg.error = EXIT_FAILURE;
		return;
	}

	first = (*head)->n;
	second = (*head)->next->n;

	sum = first + second;
	(*head)->next->n = sum;
	pop_st(head, line_number);
}
