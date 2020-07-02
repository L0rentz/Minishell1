/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** check_if_builtins
*/

#include "my.h"

void check_command(char **str, int *check, dlist_t *mylist, char **prompt)
{
    char *tab[] = {
        "env",
        "setenv",
        "unsetenv",
        "cd",
        NULL,
    };
    void (*function[4])() = {print_list, my_setenv, my_unsetenv, my_cd};
    for (int j = 0; tab[j] != NULL; j++) {
        if (my_strcmp(str[0], tab[j]) == 0) {
            function[j](mylist, str, prompt);
            *check = 1;
            return;
        }
    }
}