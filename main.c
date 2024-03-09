#include "shell.h"
int main(void)
{
    char *line;
    char *args[BUFFER_SIZE];
    pid_t pid;
    int status;
    char *token;
    int i;

    while (1)
    {
	    size_t bufsize;

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

        /* Parse the input line into tokens */
        token = strtok(line, " ");
        i = 0;
        while (token != NULL)
        {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL; /* Set the last argument to NULL for execvp */

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
                fprintf(stderr, "./shell: No such file or directory\n");
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
