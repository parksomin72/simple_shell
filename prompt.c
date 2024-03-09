#include "shell.h"
/**
 * display_prompt - Display the shell prompt for user input.
 * This function prints the shell prompt to the standard output.
 */
void display_prompt(void)
{
	printf(":) ");
}

/**
 * read_command - Read a command entered by the user.
 * Return: the entered command as a string.
 */
char *read_command()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);

	if (read == -1)
	{
		return (NULL); /* End of file*/
	}
	if (line[read - 1] == '\n')
	{
		line[read - 1] = '\0';
	}
	return (line);
}
