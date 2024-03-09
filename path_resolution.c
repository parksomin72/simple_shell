#include "shell.h"

char *resolve_path(char *command) {
    char *resolved_path = NULL;
    char *path_env = getenv("PATH");
    char *path_copy;
    char *token;

    if (path_env == NULL) {
        fprintf(stderr, "Error: PATH environment variable not set.\n");
        return NULL;
    }

    path_copy = strdup(path_env);
    if (path_copy == NULL) {
        perror("strdup");
        exit(EXIT_FAILURE);
    }

    token = strtok(path_copy, ":");
    while (token != NULL) {
        /* Construct the full path by concatenating the token and command*/
        char *full_path = malloc(strlen(token) + strlen(command) + 2);
        if (full_path == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        strcpy(full_path, token);
        strcat(full_path, "/");
        strcat(full_path, command);

        /* Check if the constructed path exists and is executable*/
        if (access(full_path, X_OK) == 0) {
            resolved_path = full_path;
            break;
        }

        free(full_path);
        token = strtok(NULL, ":");
    }

    free(path_copy);
    return (resolved_path);
}
