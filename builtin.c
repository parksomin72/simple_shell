#include "shell.h"

void execute_builtin_command(char *command)
{
	char **env;

    /* Code to execute built-in commands*/
	if (strcmp(command, "exit") == 0) {
        exit(0); /* Exit the shell*/
    } else if (strcmp(command, "env") == 0) {
        /* Print the environment variables */
        extern char **environ;
        for (env = environ; *env != NULL; env++) {
            printf("%s\n", *env);
        }
    } else {
        printf("Unknown command: %s\n", command);
    }
}
