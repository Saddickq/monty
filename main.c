#include "monty.h"


int main(int argc, char **argv)
{
	int len;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	
	read_file_lines(argv[1]);
	return (0);
}
