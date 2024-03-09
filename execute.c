#include "shell.h"
/**
 * Function to execute a command.
 */
void execute_command(char **args)
{
    pid_t pid;
    int status;

    /* Count the number of arguments */
    int arg_count = 0;
    while (args[arg_count] != NULL)
    {
        arg_count++;
    }

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        /* Child process */
        /* Sort arguments if the command is ls */
        if (strcmp(args[0], "ls") == 0)
	{
            /* Sort the arguments */
            qsort(&args[1], arg_count - 1, sizeof(char *), compare_strings);
        }
        /* Execute the command */
        if (execvp(args[0], args) == -1)
	{
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* Parent process */
        waitpid(pid, &status, 0);
    }
}
