#include "shell.h"

/**
 * execute_command - Executes the given command.
 * @command: The command to execute.
 * @args: The command arguments.
 *
 * Return: Always 0
 */
int execute_command(char *command) {
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        return (EXIT_FAILURE);
    } else if (child_pid == 0) {
        /* Child process */
        execlp(command, command, (char *)NULL);
        /* If exec returns, it must have failed */
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {
        /* Parent process */
        if (waitpid(child_pid, &status, 0) == -1) {
            perror("waitpid");
            return (EXIT_FAILURE);
        }
    }
    return (EXIT_SUCCESS);
}
