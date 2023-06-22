#include "monty.h"
/**
 * free_stack_t - free the memory used by stack_t
 * @head: the pointer to the head of the lists
 * Return: void
*/
void free_stack_t(stack_t *head)
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
