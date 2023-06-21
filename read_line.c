#include "monty.h"

void process_line(char *line)
{
	char *opcode = NULL;
	char **tokens;
	int count = 0, push_number;
	
	tokens = tokenise_line(line);

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
	free(tokens);
}

/**
 * read_file_lines - reads the lines from a file 
 * @file_name: The file to be read
 * Return: void
*/
void *read_file_lines(char *file_name)
{
	int line_number = 0;
	char *buffer = NULL;
	size_t size = 0;
	FILE *file_des = open_file(file_name);
	ssize_t line = 0;
    
	while (getline(&buffer, &size, file_des) != -1)
	{
		process_line(buffer);
		line_number++;
	}
	free(buffer);
	fclose(file_des);
}


FILE *open_file(char *file)
{
	FILE *fd = fopen(file, "r");

	int len = strlen("Error: Can't open file ");
	if (fd == NULL)
	{
		write(STDERR_FILENO, "Error: Can't open file ", len);
		write(STDERR_FILENO, file, strlen(file));
		write(STDERR_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
