#include "shell.h"
/**
 * main - Entry point
 * Return: alwys 0 (Seccuss)
 */
int main(void) {
    char input[MAX_INPUT_LENGTH];
    char *args[MAX_ARGS];
    int status;
    char *token;
    int i;

    while (1) {
        printf("($) ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            perror("fgets");
            exit(EXIT_FAILURE);
        }

        /* Tokenize the input */
        token = strtok(input, DELIMITER);
        i = 0;
        while (token != NULL && i < MAX_ARGS - 1) {
            args[i++] = token;
            token = strtok(NULL, DELIMITER);
        }
        args[i] = NULL;

        /* Execute the command */
        execute_command(args);

        /* Wait for child process to terminate*/
        wait(&status);
    }

    return (0);
}
