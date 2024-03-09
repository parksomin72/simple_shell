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
            char **argv = malloc(sizeof(char *) * 2); /* Allocate memory for argv*/
            if (argv == NULL) {
                perror("malloc");
                exit(EXIT_FAILURE);
            }
            argv[0] = buffer; /* First argument is the command*/
            argv[1] = NULL; /* Null-terminate the array*/

            envp = NULL;
            if (execve(buffer, argv, envp) == -1) {
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
