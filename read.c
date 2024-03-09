#include "shell.h"
void read_command(char *buffer, size_t size)
{
	ssize_t read_bytes;
	
	read_bytes = read(STDIN_FILENO, buffer, size);
	if (read_bytes == -1)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
	if (read_bytes == 0)
	{
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	buffer[read_bytes - 1] = '\0';
}
