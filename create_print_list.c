/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** create_print_list
*/

#include "my.h"

dlist_t *new_list(void)
{
    return (NULL);
}

bool is_empty_list(dlist_t *li)
{
    if (li == NULL)
        return true;
    return false;
}

dlist_node_t *new_dlist_node(char *str)
{
    dlist_node_t *element;
    element = malloc(sizeof(*element));
    element->name = malloc(sizeof(char) * my_strlen(str) + 1);
    int i = 0;
    for (; str[i] != '\0' && str != NULL; i++)
        element->name[i] = str[i];
    element->name[i] = '\0';
    element->next = NULL;
    element->back = NULL;
    return (element);
}

void print_list(dlist_t *li)
{
    if (is_empty_list(li))
        return;
    dlist_node_t *tmp = li->begin;
    while (tmp != NULL) {
        my_printf("%s\n", tmp->name);
        tmp = tmp->next;
    }
}

void print_list_rev(dlist_t *li)
{
    if (is_empty_list(li))
        return;
    dlist_node_t *tmp = li->end;
    while (tmp != NULL) {
        my_printf("%s\n", tmp->name);
        tmp = tmp->back;
    }
}