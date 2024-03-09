#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define BUFSIZE 1024

void prompt() {
    printf("#cisfun$ ");
}

int main(void) {
    pid_t pid;
    char **argv;
    int argc;
    char *token;
    char **envp;
    char *buffer;
    size_t bufsize = BUFSIZE;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if (buffer == NULL) {
        perror("Unable to allocate buffer");
        exit(EXIT_FAILURE);
    }

    while (1) {
        prompt();

        if (getline(&buffer, &bufsize, stdin) == -1) {
            if (feof(stdin)) {
                printf("\n");
                break;
            } else {
                perror("getline");
                exit(EXIT_FAILURE);
            }
        }

        buffer[strcspn(buffer, "\n")] = '\0'; /* Remove trailing newline*/

        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            argv = malloc(sizeof(char *) * (strlen(buffer) + 1)); /* Allocate memory for argv */
            if (argv == NULL) {
                perror("malloc");
                exit(EXIT_FAILURE);
            }

            argc = 0;
            token = strtok(buffer, " "); /* Tokenize the command line */
            while (token != NULL) {
                argv[argc++] = token;
                token = strtok(NULL, " ");
            }
            argv[argc] = NULL; /* Null-terminate the array */

            envp = NULL; /* Environment variables array */
            if (execve(argv[0], argv, envp) == -1) {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }

    free(buffer);
    return (EXIT_SUCCESS);
}
