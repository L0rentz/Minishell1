/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** Displays, one-by-one, the characters of a string.
*/

#include "my_printf.h"

void my_putstr_nonprintable(va_list ap)
{
    char *str = va_arg(ap, char *);
    if (str == 0) {
        my_putstr("(null)");
        return;
    }
    while (*str) {
        if (*str < 32 || *str >= 127) {
            my_putchar('\\');
            my_putnbr_uoctal(*str);
        }
        else
            my_putchar(*str);
        str++;
    }
}
