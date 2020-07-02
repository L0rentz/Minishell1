/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** env_linked_list_tab
*/

#include "my.h"

dlist_t *env_to_linked_list(char **envp)
{
    dlist_t *mylist = new_list();
    for (int i = 0; envp[i] != NULL; i++) {
        mylist = push_back_list(mylist, envp[i]);
    }
    return (mylist);
}

char **env_linked_list_to_tab_array(dlist_t *mylist)
{
    dlist_node_t *tmp = mylist->begin;
    char **tab = malloc(sizeof(char *) * (mylist->length + 1));
    int i = 0;
    for (int j = 0; tmp != NULL; i++, tmp = tmp->next, j = 0) {
        tab[i] = malloc(sizeof(char) * (my_strlen(tmp->name) + 1));
        for (; tmp->name[j] != '\0'; j++)
            tab[i][j] = tmp->name[j];
        tab[i][j] = '\0';
    }
    tab[i] = NULL;
    return (tab);
}