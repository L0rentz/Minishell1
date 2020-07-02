/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_utils
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;
    if (str == 0)
        return (0);
    for (; str[i]; i++);
    return (i);
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int size_dest = my_strlen(dest);
    while (src[i] != '\0') {
        dest[size_dest++] = src[i];
        i++;
    }
    dest[size_dest++] = '\0';
    return (dest);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    for (; s1[i] == s2[i] && s1[i] != '\0'; i++);
    return (s1[i] - s2[i]);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    for (; (s1[i] == s2[i] && s1[i] != '\0') && i < n; i++);
    return (s1[i] - s2[i]);
}

int my_str_isalpha(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z')
            && str[i] == '_')
            return (1);
        i++;
    }
    return (0);
}
