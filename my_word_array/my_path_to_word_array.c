/*
** EPITECH PROJECT, 2019
** my_str_to_word_array.c
** File description:
** Splits a string into words
*/

#include "../my.h"

int is_path(char c)
{
    if (c == '=' || c == ':')
        return (1);
    return (0);
}

char **my_path_to_word_array(char const *str)
{
    int words = 0, j = 0, x = 0;
    if (my_strlen(str) == 0 || str == NULL) return (NULL);
    for (int i = 0; str[i + 1] != '\0'; i++)
        if (is_path(str[i]) == 1 && is_path(str[i + 1]) == 0) words++;
    if (is_path(str[0]) == 0) words++;
    char **ptr = malloc(sizeof(char *) * (words + 1));
    ptr[words] = NULL;
    for (int i = 0, len = 0; str[i] != '\0'; len = 0) {
        for (; is_path(str[i]) == 0 && str[i] != '\0'; i++, len++);
        for (; is_path(str[i]) == 1 && str[i] != '\0'; i++);
        if (len != 0)
            ptr[j] = malloc(sizeof(char) * len + 1), ptr[j][len] = '\0', j++;
    }
    for (; is_path(str[x]) == 1 && str[x] != '\0'; x++);
    for (int i = 0, k = 0; ptr[i] != NULL && str[x] != '\0'; k = 0, i++) {
        for (; is_path(str[x]) == 0 && str[x] != '\0'; x++, k++)
            ptr[i][k] = str[x];
        ptr[i][k] = '\0';
        for (; is_path(str[x]) == 1 && str[x] != '\0'; x++);
    } return (ptr);
}
