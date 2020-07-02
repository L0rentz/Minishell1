/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf
*/

#include "my_printf.h"

void my_putsave(int save, char const *format, int i)
{
    if (format[save + 1] != format[i]) {
        my_putchar(format[save]);
        my_putchar(' ');
        my_putchar(format[i]);
    }
    else {
        my_putchar(format[save]);
        my_putchar(format[i]);
    }
}

void my_putcharswitch(char const format, va_list ap)
{
    if (format == '%')
        my_putchar('%');
    if (format == 'c') {
        char c = va_arg(ap, int);
        my_putchar(c);
    }
}

void my_printf_loop(const char *format, void (*function[10])(), char *flags,
                    va_list ap)
{
    int z = 0;
    int i = 0;
    int save = 0;
    for (; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            save = i;
            if (format [i+1] != '\0')
                i++;
            for (; format[i] == ' ' && format[i+1] != '\0'; i++);
            for (; format[i] != flags[z] && flags[z] != '\0'; z++);
            if (format[i] == flags[z])
                function[z](ap);
            else if (format[i] == '%' || format[i] == 'c')
                my_putcharswitch(format[i], ap);
            else
                my_putsave(save, format, i);
            z = 0;
        }
        else my_putchar(format[i]);
    }
}

int my_printf(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    int z = 0;
    char *flags = "sSdioxXpub";
    void (*function[10])() = {my_putstr_ap, my_putstr_nonprintable,
                                my_put_nbr_ap, my_put_nbr_ap,
                                my_putnbr_uoctal_ap, my_putnbr_hexamin_ap,
                                my_putnbr_hexamaj_ap, my_putnbr_address,
                                my_put_unbr_ap, my_putnbr_bin_ap};
    my_printf_loop(format, function, flags, ap);
    va_end(ap);
    return (0);
}
