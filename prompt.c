#include "shell.h"

void display_prompt()
{
	printf("$ ");
}

char *read_command()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);

	if (read == -1)
	{
		return NULL; /* End of file*/
	}
	if (line[read - 1] == '\n')
	{
		line[read - 1] = '\0';
	}
	return line;
}
