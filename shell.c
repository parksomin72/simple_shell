#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PROMPT "#cisfun$ "

/**
 * main - Entry point of the shell program.
 *
 * Return: Always returns 0.
 */
int main(void)
{
    size_t bufsize = 0;
    ssize_t characters;
    pid_t pid;
    int status;
    char *command = NULL;

    while (1)
    {
        /* Display prompt */
        printf("%s", PROMPT);

        /* Read command from user */
        characters = getline(&command, &bufsize, stdin);
        if (characters == -1)
        {
            /* Handle end of file (Ctrl+D) */
            if (feof(stdin))
            {
                printf("\n");
                break;
            }
            perror("getline");
            exit(EXIT_FAILURE);
        }

        /* Remove newline character from command */
        command[characters - 1] = '\0';

        /* Create child process */
        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0)
        {
            /* Child process: execute command */
            execute_command(command);
            exit(EXIT_SUCCESS); /* Successful execution */
        }
        else
        {
            /* Parent process: wait for child to terminate */
            wait(&status);
        }
    }

    /* Free dynamically allocated memory */
    free(command);

    return (0);
}
