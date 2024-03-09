#include "shell.h"

int main(void)
{
    char *line;
    char **args;

    while (1)
    {
        size_t bufsize;

        printf(":) ");
        line = NULL;
        bufsize = 0;
        if (getline(&line, &bufsize, stdin) == -1)
        {
            if (feof(stdin))
            {
                printf("\n");
                free(line);
                exit(EXIT_SUCCESS);
            }
            else
            {
                perror("getline");
                exit(EXIT_FAILURE);
            }
        }

        /* Remove trailing newline character */
        line[strcspn(line, "\n")] = '\0';

        /* Tokenize input */
        args = tokenize_input(line);

        /* Execute command */
        execute_command(args);

        free(line);
        free(args);
    }

    return (0);
}
