#include "shell.h"
/**
 * Function to read input line
 */
char *read_line(void)
{
    char *line;
    size_t bufsize;

    line = NULL;
    bufsize = 0;

    if (getline(&line, &bufsize, stdin) == -1)
    {
        perror("getline");
        exit(EXIT_FAILURE);
    }

    return (line);
}

/**
 * Function to parse input line
 */
char **parse_line(char *line)
{
    int bufsize, position;
    char **tokens;
    char *token;

    bufsize = BUFFER_SIZE;
    position = 0;
    tokens = malloc(bufsize * sizeof(char *));

    if (!tokens)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " \t\r\n\a");
    while (token != NULL)
    {
        tokens[position++] = token;

        if (position >= bufsize)
	{
            bufsize += BUFFER_SIZE;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
	    {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[position] = NULL;
    return (tokens);
}
/**
 * Function to tokenize the input line.
 */
char **tokenize_input(char *line)
{
	int position;
    int bufsize;
    char **tokens;
    char *token;

   bufsize =  BUFFER_SIZE;
   position = 0;
    tokens = malloc(bufsize * sizeof(char *));

    if (!tokens)
    {
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, DELIMITER);
    while (token != NULL)
    {
        tokens[position++] = token;

        if (position >= bufsize)
        {
            bufsize += BUFFER_SIZE;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                fprintf(stderr, "Allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, DELIMITER);
    }
    tokens[position] = NULL;
    return (tokens);
}
