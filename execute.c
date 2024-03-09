#include "shell.h"

/**
 * Function to execute a command.
 */
void execute_command(char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        /* Child process */
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
