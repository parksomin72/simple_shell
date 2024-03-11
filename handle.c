#include "shell.h"

void handle_user_input(void)
{
	char command[300];
	char *token;

	while (1)
	{
		display_prompt();
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			if (ferror(stdin))
			{
				handle_getline_error();
			}
			printf("\n");
			break;
		}

		/* Remove the newline character from the command */
		command[strcspn(command, "\n")] = '\0';

		token = strtok(command, ";");

		while (token != NULL)
		{
			char *args[300];
			int arg_count = 0;

			/* Tokenize the input */
			char *arg_token = strtok(token, " ");

			while (arg_token != NULL)
			{
				args[arg_count] = arg_token;
				arg_count++;
				arg_token = strtok(NULL, " ");
			}
			args[arg_count] = NULL;
			if (arg_count > 0)
			{
				if (strcmp(args[0], "exit") == 0)
				{
					break;
				}
				else if (strcmp(args[0], "ls") == 0)
				{
					execute_command(args[0], args);
				}
				else if (strcmp(args[0], "hbtn_ls") == 0)
				{
					execute_command("cp", args);
				}
				else
				{
					printf("Command not found: %s\n", args[0]);
				}
			}
			token = strtok(NULL, ";");
		}
	}
}


/********************* HANDLE PIPED INPUT FUNCTION **************************/

/**
 * handle_piped_input - Handle piped input in non-interactive mode
 */
void handle_piped_input(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int arg_count;
	char *args[300];
	char *token;

	while ((read = getline(&line, &len, stdin)) != -1)
	{
		line[read - 1] = '\0'; /* Remove newline */

		/* toenize the input for piping */
			arg_count = 0;
		token = strtok(line, " ");

		while (token != NULL)
		{
			args[arg_count] = token;
			arg_count++;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

		if (execute_command(args[0], args) == -1)
		{
			fprintf(stderr, "Failed to execute command: %s\n", args[0]);
		}
	}
	free(line);
}
