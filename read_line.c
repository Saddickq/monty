#include "monty.h"

void process_line(char *line, unsigned int line_number)
{
	char *opcode = NULL;
	char **tokens = NULL;
	int count = 0, push_number;

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
	
	int i = 0;
	while (tokens[i] != NULL)
        {
		printf("%s", tokens[i]);
		i++;
	}
	printf("\n");

	opcode = tokens[0];
	if (count == 2)
	{
		push_number = atoi(tokens[1]);
	}
	operate(opcode, push_number, line_number);
	//free(tokens);
}

/**
 * read_file_lines - reads the lines from a file 
 * @file_name: The file to be read
 * Return: void
*/
void *read_file_lines(char *file_name)
{
	int line_number = 1;
	char *buffer = NULL;
	size_t size = 0;
	FILE *file_des = open_file(file_name);
	ssize_t line = 0;
    
	while (getline(&buffer, &size, file_des) != -1)
	{
		process_line(buffer, line_number);
		line_number++;
	}
	free(buffer);
	fclose(file_des);
}


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
