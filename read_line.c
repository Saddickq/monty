#include "monty.h"
/**
 * process_line - process the lines from getline
 * @line: the line to be processed
 * @head: the head of the linked lists
 * @line_number: the line number of line processed
 * Return: void
 */
void process_line(char *line, stack_t **head, unsigned int line_number)
{
	char *opcode = NULL;
	char **tokens = NULL;
	int count = 0;

	tokens = tokenise_line(line);

	if (tokens == NULL)
		return;
	while (tokens[count] != NULL)
		count++;

	if (count == 0)
	{
		free(tokens);
		return;
	}

	opcode = tokens[0];
	if (strcmp(opcode, "push") == 0)
	{
		if (tokens[1] == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			global_msg.error = EXIT_FAILURE;
			return;
		}
		global_msg.push_number = atoi(tokens[1]);
	}
	operate(opcode, head, line_number);
	free(tokens);
}

/**
 * read_file_lines - reads the lines from a file
 * @file_name: The file to be read
 * Return: void
*/
void read_file_lines(char *file_name)
{
	stack_t *head = NULL;
	int line_number = 1;
	char *buffer = NULL;
	ssize_t line = 0;
	size_t size = 0;

	FILE *file_des = open_file(file_name);

	line = getline(&buffer, &size, file_des);
	while (line != -1)
	{
		if (global_msg.error == 1)
			break;
		process_line(buffer, &head, line_number);
		line = getline(&buffer, &size, file_des);
		line_number++;
	}
	free_stack(head);
	free(buffer);
	fclose(file_des);
}

/**
 * open_file - attempt to open a file for reading
 * @file: filepath to be opened
 * Return: file descriptor
 */
FILE *open_file(char *file)
{
	FILE *fd = fopen(file, "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file ");
		fprintf(stderr, "%s\n", file);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
