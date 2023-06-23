#include "monty.h"
/**
 * mul_st - multiply the two topmost element in the stack
 * @head: the pointer to the head node
 * @line_number: the line of execution
 * Return: void
 */
void mul_st(stack_t **head, unsigned int line_number)
{
	int first, second;
	int pro = 0;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		global_msg.error = EXIT_FAILURE;
		return;
	}

	first = (*head)->n;
	second = (*head)->next->n;

	pro = second * first;
	(*head)->next->n = pro;
	pop_st(head, line_number);
}

/**
 * mod_st - find the remainder after dividing the
 * two topmost element in the stack
 *
 * @head: the pointer to the head node
 * @line_number: the line of execution
 * Return: void
 */
void mod_st(stack_t **head, unsigned int line_number)
{
	int first, second;
	int modu = 0;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		global_msg.error = EXIT_FAILURE;
		return;
	}

	first = (*head)->n;
	second = (*head)->next->n;
	if (first == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		global_msg.error = EXIT_FAILURE;
		return;
	}

	modu = second % first;
	(*head)->next->n = modu;
	pop_st(head, line_number);
}

void pchar_st(stack_t **head, unsigned int line_number)
{
	int number = 0;
	char ascii;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		global_msg.error = EXIT_FAILURE;
		return;
	}

	while ((*head)->prev != NULL)
	{
		*head = (*head)->prev;
	}
	number = (*head)->n;
	if (number < 65 || number > 122)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		global_msg.error = EXIT_FAILURE;
		return;
	}
	ascii = number;
	printf("%c\n", ascii);
}
