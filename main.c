#include "shell.h"
/**
 * main - Entry point
 * Return: always 0 (seccuss)
 */
int main(void)
{
	char *command;

	while (1)
	{
		display_prompt();
		command = read_command();
		if (command == NULL)
		{
			break; /* Handle end of file (Ctrl+D)*/
		}
		execute_command(command);
		free(command);
	}
	return (0);
}
