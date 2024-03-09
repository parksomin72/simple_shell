#include "shell.h"
/**
 * Comparison function for sorting strings.
 */
int compare_strings(const void *a, const void *b)
{
    const char **str1 = (const char **)a;
    const char **str2 = (const char **)b;
    return strcmp(*str1, *str2);
}
