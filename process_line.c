#include "monty.h"


char **tokenise_line(char *line)
{
	char **tokens = NULL;
	char *token = NULL;
	int idx = 0, len;
	char *copy = NULL;

	tokens = malloc(sizeof(char *) * 3);
	if (tokens == NULL)
	{
		len = strlen("Error: malloc failed\n");
		write(STDERR_FILENO, "Error: malloc failed\n", len);
		free(line);
		exit(EXIT_FAILURE);
	}

	copy = strdup(line);
	token = strtok(copy, DELIM);
	while (token != NULL && idx < 2)
	{
		tokens[idx] = token;
		token = strtok(NULL, DELIM);
		idx++;
	}
	tokens[idx] = NULL;
	//free(copy);
	return (tokens);
}

void operate(char *opcode)
{

}
void free_line(char **lines)
{
	int i;

	if (lines == NULL)
		return;
	for (i = 0; lines[i] != NULL; i++)
	{
		free(lines[i]);
	}
	free(lines);
}
