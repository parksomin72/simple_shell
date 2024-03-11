#include "shell.h"
/************ Handle fork error **************/
/**
 * handle_fork_error - Handles error during fork system call.
 */

void handle_fork_error(void)
{
	perror("fork");
}

/*********** Handle execvp error ************/
/**
 * handle_execvp_error - Handles error during execvp system call.
 * @command: The command that caused the error.
 */

void handle_execvp_error(const char *command)
{
	perror(command);
	exit(EXIT_FAILURE);
}

/*********** Handle waitpid error *****************/
/**
 * handle_waitpid_error - Handles error during waitpid system call.
 */

void handle_waitpid_error(void)
{
	perror("waitpid");
}

/*********** Handle getline error **********/
/**
 * handle_getline_error - Handles error during getline system call.
 */

void handle_getline_error(void)
{
	perror("getline");
}
