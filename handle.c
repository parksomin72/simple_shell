#include "shell.h"
void handle_user_input(void) {
    char command[BUFFER_SIZE];
    if (fgets(command, sizeof(command), stdin) == NULL) {
        printf("\n");
        exit(EXIT_SUCCESS);
    }
    /* Remove the newline character */
    command[strcspn(command, "\n")] = '\0';

    execute_command(command);
}
