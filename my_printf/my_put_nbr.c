/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** Displays the number given as a parameter.
*/

#include "my_printf.h"

void my_put_nbr(long long nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 0) {
        if (nb >= 10) {
            my_put_nbr(nb / 10);
            my_putchar(nb % 10 + '0');
        }
        else
            my_putchar(nb % 10 + '0');
    }
}

void my_put_nbr_ap(va_list ap)
{
    long long nb = va_arg(ap, long long);
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 0) {
        if (nb >= 10) {
            my_put_nbr(nb / 10);
            my_putchar(nb % 10 + '0');
        }
        else
            my_putchar(nb % 10 + '0');
    }
}