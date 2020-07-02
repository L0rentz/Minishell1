/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** error_handling
*/

#include "my.h"

void print_error(int error)
{
    if (WTERMSIG(error) == 11) {
        if (WCOREDUMP(error) == 0) my_printf("Segmentation fault\n");
        else my_printf("Segmentation fault (core dumped)\n");
    } else if (WTERMSIG(error) == 8) {
        if (WCOREDUMP(error) == 0) my_printf("Floating exception\n");
        else my_printf("Floating exception (core dumped)\n");
    }
}

void exec_error(void)
{
    my_printf("./my_printf: Permission denied.\n");
}