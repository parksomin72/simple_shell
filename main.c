#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int main()
{
    char command[MAX_COMMAND_LENGTH];
    pid_t pid;

    while (1)
    {
        printf("#cisfun$ ");
        fflush(stdout);

        /* Read command from user */
        if (fgets(command, sizeof(command), stdin) == NULL)
	{
            /* Handling Ctrl+D (end of file) */
            printf("\n");
            break;
        }

        /* Remove trailing newline character */
        command[strcspn(command, "\n")] = 0;

        /* Fork a child process */
        pid = fork();

        if (pid == -1)
	{
            /* Fork failed */
            perror("fork");
            exit(EXIT_FAILURE);
        }
	else if (pid == 0)
	{
            /* Child process */
            /* Execute the command */
            if (execlp(command, command, (char *)NULL) == -1) {
                /* If exec fails, print error */
                printf("%s: command not found\n", command);
                exit(EXIT_FAILURE);
            }
        }
	else
	{
            /* Parent process */
            /* Wait for child to terminate */
            wait(NULL);
        }
    }

    return (0);
}
