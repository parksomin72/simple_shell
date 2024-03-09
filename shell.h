#ifndef _SHELL_H_
#define _SHELL_H_

#define BUFFER_SIZE 1024
#define DELIMITER " \t\r\n\a"
/* header */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
/** Function declarations **/
char *read_line(void);
char **parse_line(char *line);
void execute_command(char **args);
void free_args(char **args);
char **tokenize_input(char *line);
int compare_strings(const void *a, const void *b);

#endif /*SHELL_H*/
