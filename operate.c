#include "monty.h"

void operate(char *opcode, stack_t **head, unsigned int line_number)
{
	int idx = 0;

	instruction_t command;

	instruction_t inst[] = {
		{"push", push_st},
		{"pop", pop_st},
		{"pall", print_st},
		/**{"pint", take_first},
		{"add", add_st},
		{"swap", swap_st},
		{"nop", NULL},*/
		{NULL, NULL}
	
	};
	while (inst[idx].opcode != NULL && (strcmp(inst[idx].opcode, opcode)) != 0)
		idx++;

	command = inst[idx];
	if (command.opcode == NULL)
	{
		fprintf(stderr,"L%d: unknown instruction %s\n", line_number, opcode);
		global_msg.error = EXIT_FAILURE;
		return;
	}
	inst[idx].f(head, line_number);
}
