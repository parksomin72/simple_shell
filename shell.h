#ifndef _SHELL_H_
#define _SHELL_H_

#define BUFFER_SIZE 1024
/* header */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
/** Function declarations **/
char *read_line(void);
char **parse_line(char *line);
int execute_command(char **args);
void free_args(char **args);

#endif /*SHELL_H*/
