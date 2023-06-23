#include "monty.h"
/**
 * operate - executes the opcode in the line from
 * the file read
 * @opcode: the operation code to execute
 * @head: pointer to the head of the stack
 * @line_number: the line at execution
 * Return: void
 */
void operate(char *opcode, stack_t **head, unsigned int line_number)
{
	int idx = 0;

	instruction_t command;

	instruction_t inst[] = {
		{"push", push_st},
		{"pop", pop_st},
		{"pall", print_st},
		{"pint", take_first},
		{"add", add_st},
		{"sub", sub_st},
		{"div", div_st},
		{"swap", swap_st},
		{"nop", NULL},
		{NULL, NULL}
	};
	while (inst[idx].opcode != NULL && (strcmp(inst[idx].opcode, opcode)) != 0)
		idx++;

	command = inst[idx];
	if (command.opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		global_msg.error = EXIT_FAILURE;
		return;
	}
	if (inst[idx].f == NULL)
		return;

	inst[idx].f(head, line_number);
}
