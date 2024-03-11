#include "shell.h"

/**
 * execute_command - Executes the given command.
 * @command: The command to execute.
 * @args: The command arguments.
 *
 * Return: Always 0
 */

int execute_command(char *command, char *args[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		handle_fork_error();
		return (-1);
	}
	else if (child_pid == 0)
	{
		/*Child process */
		if (command != NULL)
		{
			/* use execvp to execute the command with arguments */
			execvp(command, args);
			handle_execvp_error(command);
			exit(EXIT_FAILURE);
	}
		else
		{
			execlp("/bin/sh", "/bin/sh", (char *)NULL);
			handle_execvp_error("/bin/sh");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		if (waitpid(child_pid, &status, 0) == -1)
		{
			handle_waitpid_error();
			return (-1);
		}
	}
	return (0);
}
