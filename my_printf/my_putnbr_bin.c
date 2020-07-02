/*
** EPITECH PROJECT, 2019
** my_putnbr_base
** File description:
** Converts and displays a decimal num into a given base
*/

#include "my_printf.h"

void my_putnbr_bin(unsigned int nbr)
{
    if (nbr >= 2)
        my_putnbr_bin(nbr / 2);
    if (nbr % 2 < 10)
        my_putchar(nbr % 2 + '0');
    else my_putchar((nbr % 2) + 55);
}

void my_putnbr_bin_ap(va_list ap)
{
    unsigned int nbr = va_arg(ap, unsigned int);
    if (nbr >= 2)
        my_putnbr_bin(nbr / 2);
    if (nbr % 2 < 10)
        my_putchar(nbr % 2 + '0');
    else my_putchar((nbr % 2) + 55);
}