#include "shell.h"

/**
 * Function to execute a command
 */
int execute_command(char **args)
{
    int status;
    pid_t pid;

    pid = fork();
    if (pid == 0)
    {
        /* Child process */
        if (execvp(args[0], args) == -1)
        {
            perror("execvp");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        /* Error forking */
        perror("fork");
    }
    else
    {
        /* Parent process */
        waitpid(pid, &status, WUNTRACED);
    }

    return (1);
}
