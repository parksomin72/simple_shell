#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Function prototypes*/
void display_prompt();
char *read_command();
void execute_command(char *command);
int is_builtin_command(char *command);
char *resolve_path(char *command);
void execute_builtin_command(char *command);
void error_handler(char *message);
char **parse_arguments(char *command);

#endif /* SHELL_H */
