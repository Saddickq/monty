#include "monty.h"

void read_file_lines(char *file_name);

insert_t global_msg = {0, 0};
/**
 * main - start of program
 * @argv: argument vector
 * @argc: argument count
 * Return: global_msg.error
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_file_lines(argv[1]);

	return (global_msg.error);
}
