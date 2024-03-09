#include "shell.h"
/**
 * Function to free allocated memory for arguments
 */
void free_args(char **args)
{
    free(args);
}
