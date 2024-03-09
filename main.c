#include "shell.h"
/**
 * main - Simple shell program
 *
 * Return: Always 0
 */
int main(void)
{
	char buffer[BUFFER_SIZE];

	while (1)
	{
		display_prompt();
		read_command(buffer, BUFFER_SIZE);
		execute_command(buffer);
	}

	return EXIT_SUCCESS;
}
