/*
** EPITECH PROJECT, 2019
** my_putnbr_base
** File description:
** Converts and displays a decimal num into a given base
*/

#include "my_printf.h"

void my_putnbr_address(va_list ap)
{
    void *x = va_arg(ap, void *);
    long long unsigned int i = (long long unsigned int) x;
    if (i == 0) {
        my_putstr("(nil)");
        return;
    }
    my_putstr("0x");
    if (i >= 16)
        my_putnbr_addresshexa(i / 16);
    if (i % 16 < 10)
        my_putchar(i % 16 + '0');
    else
        my_putchar((i % 16) + 87);
}