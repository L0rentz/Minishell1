/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** header
*/

#ifndef MY_PRINTF_H
#define MY_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

void my_printf_loop(const char *format, void (*function[10])(), char *flags,
                    va_list ap);
void my_putsave(int save, char const *format, int i);
void my_putcharswitch(char const format, va_list ap);
void my_putnbr_bin_ap(va_list ap);
void my_put_unbr_ap(va_list ap);
void my_putnbr_hexamaj_ap(va_list ap);
void my_putnbr_hexamin_ap(va_list ap);
void my_putnbr_uoctal_ap(va_list ap);
void my_put_nbr_ap(va_list ap);
void my_putnbr_addresshexa(long long unsigned int nbr);
void my_putnbr_bin(unsigned int nbr);
void my_put_unbr(unsigned int nb);
void my_putnbr_address(va_list ap);
void my_putchar(char c);
void my_putnbr_base(int nbr, char const *base);
int first_check(char const *base, int len);
void my_put_nbr(long long nb);
void my_putstr_ap(va_list ap);
void my_putstr(const char *str);
int my_printf(const char *format, ...);
void my_putnbr_uoctal(unsigned int nbr);
void my_putnbr_hexamin(unsigned int nbr);
void my_putnbr_hexamaj(unsigned int nbr);
void my_putstr_nonprintable(va_list ap);

#endif
