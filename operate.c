#include "monty.h"

void operate(char *opcode, int push_number, unsigned int line_number)
{
	int idx = 0;
	instruction_t command;

	instruction_t inst[] = {
		{"push", push_st},
		{"pop", pop_st},
		{"pall", print_st},
		{"pint", take_first},
		{"add", add_st},
		{"swap", swap_st},
		{"nop", NULL},
		{NULL, NULL}
	
	}
	while (inst[idx].opcode != NULL && (strcmp(inst[idx].opcode, opcode)) != 0)
		idx++;

	command = inst[idx];
	if (command.opcode == NULL)
	{
		fprintf(stderr,"L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
