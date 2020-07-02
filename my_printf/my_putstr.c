/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** Displays, one-by-one, the characters of a string.
*/

#include "my_printf.h"

void my_putstr(char const *str)
{
    if (str == 0) {
        my_putstr("(null)");
        return;
    }
    while (*str) {
        my_putchar(*str);
        str++;
    }
}

void my_putstr_ap(va_list ap)
{
    char *str = va_arg(ap, char *);
    if (str == 0) {
        my_putstr("(null)");
        return;
    }
    while (*str) {
        my_putchar(*str);
        str++;
    }
}