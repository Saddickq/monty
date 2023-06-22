#include "monty.h"

/**
 * tokenise_line - get individual words in aline
 * @line: the line to examine
 * Return: an array of strings
 */
char **tokenise_line(char *line)
{
	char **tokens = NULL;
	char *token = NULL;
	int idx = 0;

	tokens = malloc(sizeof(char *) * 3);

	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		global_msg.error = EXIT_FAILURE;
		return (NULL);
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
