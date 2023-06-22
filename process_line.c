#include "monty.h"


char **tokenise_line(char *line)
{
	char **tokens = NULL;
	char *token = NULL;
	int idx = 0, len;

	tokens = malloc(sizeof(char *) * 3);

	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(line);
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIM);
	while (token != NULL && idx < 2)
	{
		tokens[idx] = token;
		token = strtok(NULL, DELIM);
		idx++;
	}
	tokens[idx] = NULL;
	return (tokens);
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
