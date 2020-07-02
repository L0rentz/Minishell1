/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_prompt
*/

#include "my.h"

void update_oldpwd(dlist_t *mylist, char *pwd)
{
    dlist_node_t *tmp = mylist->begin;
    while (tmp != NULL) {
        if (my_strlen(tmp->name) >= 6
            && my_strncmp(tmp->name, "OLDPWD", 5) == 0)
            break;
        tmp = tmp->next;
    }
    if (tmp == NULL) {
        char *new = malloc(sizeof(char) * 1);
        new[0] = '\0';
        return;
    }
    char *new = malloc(sizeof(char) * my_strlen(pwd) + 8);
    new[0] = '\0';
    new = my_strcat(new, "OLDPWD=");
    new = my_strcat(new, pwd);
    free(tmp->name);
    tmp->name = new;
}

void update_pwd_prompt(dlist_t *mylist, char *prompt)
{
    dlist_node_t *tmp = mylist->begin;
    while (tmp != NULL) {
        if (my_strlen(tmp->name) >= 3 && my_strncmp(tmp->name, "PWD", 2) == 0)
            break;
        tmp = tmp->next;
    }
    if (tmp == NULL) {
        char *new = malloc(sizeof(char) * 1);
        new[0] = '\0';
        return;
    }
    char *new = malloc(sizeof(char) * my_strlen(prompt) + 5);
    new[0] = '\0';
    new = my_strcat(new, "PWD=");
    new = my_strcat(new, prompt);
    update_oldpwd(mylist, &tmp->name[4]);
    free(tmp->name);
    tmp->name = new;
}

char *find_pwd_prompt(dlist_t *mylist)
{
    dlist_node_t *tmp = mylist->begin;
    while (tmp != NULL) {
        if (my_strlen(tmp->name) >= 3 && my_strncmp(tmp->name, "PWD", 2) == 0)
            break;
        tmp = tmp->next;
    }
    if (tmp == NULL) {
        char *prompt = malloc(sizeof(char) * 1);
        prompt[0] = '\0';
        return (prompt);
    }
    int i = my_strlen(tmp->name);
    for (; tmp->name[i] != '/' && i != 0; i--);
    i++;
    char *prompt = malloc(sizeof(char) * (my_strlen(tmp->name) - i + 1));
    for (int k = i, j = 0; tmp->name[k] != '\0'; k++, j++)
        prompt[j] = tmp->name[k];
    prompt[my_strlen(tmp->name) - i] = '\0';
    return (prompt);
}