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
/**
 * pchar_st - prints the ascii value of the topmost
 * elements inthe stack
 *
 * @head: the pointer to the head node
 * @line_number: the line of execution
 * Return: void
 */
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
/**
 * pstr_st - prints the ascii value of the data in the 
 * elements of the stack
 *
 * @head: the pointer to the head node
 * @line_number: the line of execution
 * Return: void
 */
void pstr_st(stack_t **head, unsigned int line_number)
{
	char ascii_value;
	stack_t *temp = NULL;

	(void) line_number;

	if (*head == NULL)
	{
		printf("\n");
		return;
	}
	temp = *head;

	while (temp != NULL)
	{
		if (temp->n < 65 || temp->n > 122)
			break;

		ascii_value = temp->n;
		printf("%c", ascii_value);
		temp = temp->next;
	}
}
