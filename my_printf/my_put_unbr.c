/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** Displays the number given as a parameter.
*/

#include "my_printf.h"

void my_put_unbr(unsigned int nb)
{
    if (nb >= 0) {
        if (nb >= 10) {
            my_put_unbr(nb / 10);
            my_putchar(nb % 10 + '0');
        }
        else
            my_putchar(nb % 10 + '0');
    }
}

void my_put_unbr_ap(va_list ap)
{
    unsigned int nb = va_arg(ap, unsigned int);
    if (nb >= 0) {
        if (nb >= 10) {
            my_put_unbr(nb / 10);
            my_putchar(nb % 10 + '0');
        }
        else
            my_putchar(nb % 10 + '0');
    }
}
