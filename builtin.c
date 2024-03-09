#include "shell.h"
#include <stdlib.h>

/**
 * execute_builtin_command - Execute a built-in command
 * @command: The command to execute
 */
void execute_builtin_command(char *command)
{
    char *token;
    int status;

    if (strcmp(command, "exit") == 0)
    {
        /* Exit the shell with default status 0 if no argument provided */
        exit(EXIT_SUCCESS);
    }
    else if (strncmp(command, "exit ", 5) == 0)
    {
        /* Parse the argument to get the exit status */
        token = strtok(command, " ");
        token = strtok(NULL, " ");
        status = atoi(token);
        exit(status);
    }
    else if (strcmp(command, "env") == 0)
    {
        /* Print the environment variables */
        char **env;
        for (env = environ; *env != NULL; env++)
        {
            printf("%s\n", *env);
        }
    }
    else
    {
        printf("Unknown command: %s\n", command);
    }
}
