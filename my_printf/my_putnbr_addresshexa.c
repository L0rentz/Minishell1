/*
** EPITECH PROJECT, 2019
** my_putnbr_base
** File description:
** Converts and displays a decimal num into a given base
*/

#include "my_printf.h"

void my_putnbr_addresshexa(long long unsigned int nbr)
{
    if (nbr >= 16)
        my_putnbr_addresshexa(nbr / 16);
    if (nbr % 16 < 10)
        my_putchar(nbr % 16 + '0');
    else my_putchar((nbr % 16) + 87);
}