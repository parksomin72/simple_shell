#include "shell.h"
/**
 * Main function
 */
int main(void)
{
    char *line;
    size_t bufsize;
    int status;

    pid_t pid;

    while (1)
    {
        printf("#cisfun$ ");
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

        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            /* Child process */
            if (execlp(line, line, NULL) == -1)
            {
                perror("execlp");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            /* Parent process */
            waitpid(pid, &status, 0);
        }

        free(line);
    }

    return (0);
}
