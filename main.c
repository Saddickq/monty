#include "monty.h"


int main(int argc, char **argv)
{
	int len;

	if (argc < 2 || argc > 2)
	{
		len = strlen("USAGE: monty file"); 
		write(STDERR_FILENO, "USAGE: monty file", len);
		write(STDERR_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
	
	read_file_lines(argv[2]);
	return (0);
}
