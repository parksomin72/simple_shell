#include "shell.h"
int main(void) {
    char *args[] = {"ls", "test1", "test2", NULL};
    execute_command(args);
    return 0;
}
