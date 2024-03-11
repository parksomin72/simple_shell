#include "shell.h"
/**
 * main - Entry point shell program.
 *
 * Return: Always returns 0.
 */
int main(void) {
    while (1) {
        display_prompt();
        handle_user_input();
    }
    return (0);
}
