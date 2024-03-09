#include "shell.h"

/**
 * execute_builtin_command - Execute a built-in command
 * @command: The command to execute
 */
void execute_builtin_command(char *command)
{
    if (strcmp(command, "exit") == 0)
    {
        /* Exit the shell */
        exit(EXIT_SUCCESS);
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
