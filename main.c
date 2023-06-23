#include "monty.h"

insert_t global_msg = {0, 0};

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
