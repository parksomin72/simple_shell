#include "shell.h"
/**
 * error_handler - Handle errors encountered during program execution.
 * @message: The error message to be displayed
 */
void error_handler(char *message)
{
	perror(message);
}

/**
 * parse_arguments - Parse command arguments from a command string.
 * @command: string and parses it into individual arguments.
 * Return: array of pointers to the arguments.
 */
char **parse_arguments(char *command)
{
	/* Code to parse command arguments */
	char **args = NULL;
	char *token;
	int arg_count = 0;

	/* Initialize strtok with whitespace as the delimiter*/
	token = strtok(command, " \t\n");

	while (token != NULL)
	{
		arg_count++;

		args = realloc(args, sizeof(char *) * arg_count);

		if (args == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		/* Store the token in the argument array*/
		args[arg_count - 1] = strdup(token);

		if (args[arg_count - 1] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, " \t\n");
	}
	/* Add a NULL pointer at the end to indicate the end of the array */
	arg_count++;
	args = realloc(args, sizeof(char *) * arg_count);

	if (args == NULL)
	{
		perror("realloc");
		exit(EXIT_FAILURE);
	}
	args[arg_count - 1] = NULL;
	return (args);
}
