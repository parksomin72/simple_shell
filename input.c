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

    bufsize = BUFFER_SIZE;
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

    /* Check if the command is an absolute or relative path */
    if (strchr(tokens[0], '/') == NULL)
    {
	    char *cmd_path;
	    char *path;
	    char *path_copy;

        /* Search for the command in the PATH */
        path = getenv("PATH");
        if (path != NULL)
        {
            path_copy = strdup(path);
            if (path_copy != NULL)
            {
                token = strtok(path_copy, ":");
                while (token != NULL)
                {
                    cmd_path = malloc(strlen(token) + strlen(tokens[0]) + 2);
                    if (cmd_path != NULL)
                    {
                        sprintf(cmd_path, "%s/%s", token, tokens[0]);
                        if (access(cmd_path, X_OK) == 0)
                        {
                            free(tokens[0]);
                            tokens[0] = strdup(cmd_path);
                            free(cmd_path);
                            break;
                        }
                        free(cmd_path);
                    }
                    token = strtok(NULL, ":");
                }
                free(path_copy);
            }
        }
    }

    return (tokens);
}
