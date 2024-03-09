#include "shell.h"
/**
 * Main function
 */
int main(void)
{
    char *line;
    char **args;
    int status;

    do
    {
        printf("($) ");
        line = read_line();
        args = parse_line(line);
        status = execute_command(args);

        free(line);
        free_args(args);
    }
    while (status);

    return (EXIT_SUCCESS);
}
