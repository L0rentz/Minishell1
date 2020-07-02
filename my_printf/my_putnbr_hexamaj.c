/*
** EPITECH PROJECT, 2019
** my_putnbr_base
** File description:
** Converts and displays a decimal num into a given base
*/

#include "my_printf.h"

void my_putnbr_hexamaj(unsigned int nbr)
{
    if (nbr >= 16)
        my_putnbr_hexamaj(nbr / 16);
    if (nbr % 16 < 10)
        my_putchar(nbr % 16 + '0');
    else my_putchar((nbr % 16) + 55);
}

void my_putnbr_hexamaj_ap(va_list ap)
{
    unsigned int nbr = va_arg(ap, unsigned int);
    if (nbr >= 16)
        my_putnbr_hexamaj(nbr / 16);
    if (nbr % 16 < 10)
        my_putchar(nbr % 16 + '0');
    else my_putchar((nbr % 16) + 55);
}