#include "shell.h"
/**
 * execute_command - Execute a given command, handling
 *                   both built-in and external commands.
 * @command: The command to execute
 *
 */
#include "shell.h"

void execute_command(char *command) {
    if (is_builtin_command(command)) {
        execute_builtin_command(command);
    } else {
        char *resolved_path = resolve_path(command);

        if (resolved_path != NULL) {
            pid_t pid = fork();

            if (pid == -1) {
                error_handler("fork");
            } else if (pid == 0) {
                char **args = parse_arguments(command);

                execve(resolved_path, args, NULL);
                /* execve only returns if an error occurs */
                error_handler(command);
                exit(EXIT_FAILURE);
            } else {
                /* Parent process */
                int status;
                waitpid(pid, &status, 0);
                if (!WIFEXITED(status)) {
                    fprintf(stderr, "Error: Child process terminated abnormally\n");
                }
            }
            free(resolved_path);
        }
    }
}

/**
 * is_builtin_command - Check if a given command is a built-in command.
 * @command: The command to check
 * Return:1 if the command is a built-in command, 0 otherwise
 */
int is_builtin_command(char *command)
{
	return (strcmp(command, "exit") == 0 || strcmp(command, "env") == 0);
}
