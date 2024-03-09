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
                error_handler(command);
                exit(EXIT_FAILURE);
            } else {
                wait(NULL);
            }
            free(resolved_path);
        }
    }
}

int is_builtin_command(char *command) {
    return (strcmp(command, "exit") == 0 || strcmp(command, "env") == 0);
}
