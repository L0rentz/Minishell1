/*
** EPITECH PROJECT, 2019
** my_putnbr_base
** File description:
** Converts and displays a decimal num into a given base
*/

#include "my_printf.h"

void my_putnbr_uoctal(unsigned int nbr)
{
        if (nbr >= 8)
            my_putnbr_uoctal(nbr / 8);
        if (nbr % 8 < 10)
            my_putchar(nbr % 8 + '0');
}

void my_putnbr_uoctal_ap(va_list ap)
{
    unsigned int nbr = va_arg(ap, unsigned int);
    if (nbr >= 8)
        my_putnbr_uoctal(nbr / 8);
    if (nbr % 8 < 10)
        my_putchar(nbr % 8 + '0');
}