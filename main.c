#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * main - Simple shell program
 *
 * Return: Always 0
 */
int main(void)
{
    char buffer[BUFFER_SIZE];
    ssize_t read_bytes;
    pid_t child_pid;
    int status;
    char *envp[] = {NULL};

    while (1)
    {
        printf("#cisfun$ ");
        read_bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE);
        if (read_bytes == -1)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }
        if (read_bytes == 0)
        {
            printf("\n");
            break;
        }
        buffer[read_bytes - 1] = '\0';

        child_pid = fork();
        if (child_pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (child_pid == 0)
        {
            char *args[2];
            args[0] = buffer;
            args[1] = NULL;
            if (execve(buffer, args, envp) == -1)
            {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(&status);
        }
    }

    return (EXIT_SUCCESS);
}
