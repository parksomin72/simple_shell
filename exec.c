#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * execute_command - Executes the given command.
 * @command: The command to execute.
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_command(char *command)
{
    char **argv;
    char *const envp[] = {NULL};

    /* Allocate memory for argv */
    argv = malloc(2 * sizeof(char *));
    if (argv == NULL)
    {
        perror("malloc");
        return (-1);
    }

    /* Set command as the first argument */
    argv[0] = command;
    argv[1] = NULL;

    /* Execute command using execve */
    if (execve(command, argv, envp) == -1)
    {
        perror("execve");
        free(argv);  /* Free dynamically allocated memory */
        return (-1);
    }

    /* Free dynamically allocated memory */
    free(argv);

    return (0);
}
