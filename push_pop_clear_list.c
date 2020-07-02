/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** push_pop_clear_list
*/

#include "my.h"

dlist_t *push_back_list(dlist_t *li, char *str)
{
    dlist_node_t *element = new_dlist_node(str);
    if (is_empty_list(li)) {
        li = malloc(sizeof(*li));
        li->length = 0;
        li->begin = element;
        li->end = element;
    }
    else {
        li->end->next = element;
        element->back = li->end;
        li->end = element;
    }
    li->length++;
    return (li);
}

dlist_t *push_front_list(dlist_t *li, char *str)
{
    dlist_node_t *element = new_dlist_node(str);
    if (is_empty_list(li)) {
        li = malloc(sizeof(*li));
        li->length = 0;
        li->begin = element;
        li->end = element;
    }
    else {
        li->begin->back = element;
        element->next = li->begin;
        li->begin = element;
    }
    li->length++;
    return (li);
}

dlist_t *pop_front_list(dlist_t *li)
{
    if (is_empty_list(li))
        return (new_list());
    if (li->begin == li->end) {
        free (li->begin->name);
        free (li->begin);
        free (li);
        return (new_list());
    }
    dlist_node_t *tmp = li->begin;
    li->begin = li->begin->next;
    li->begin->back = NULL;
    tmp->next = NULL;
    tmp->back = NULL;
    free(tmp->name);
    free (tmp);
    li->length--;
    return (li);
}

dlist_t *pop_back_list(dlist_t *li)
{
    if (is_empty_list(li))
        return (new_list());
    if (li->end == li->begin) {
        free (li->begin->name);
        free (li->begin);
        free (li);
        return (new_list());
    }
    dlist_node_t *tmp = li->end;
    li->end = li->end->back;
    li->end->next = NULL;
    tmp->next = NULL;
    tmp->back = NULL;
    free(tmp->name);
    free (tmp);
    li->length--;
    return (li);
}

dlist_t *clear_list(dlist_t *li)
{
    while (!is_empty_list(li))
        li = pop_back_list(li);
    return (new_list());
}