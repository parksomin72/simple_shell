#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 64
#define DELIMITER " \t\r\n\a"

void execute_command(char **args);


#endif
