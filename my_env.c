/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_env
*/

#include "my.h"

void my_setenv_replace(dlist_node_t *tmp, char **str)
{
    int i = 0, j = 0;
    for (; tmp->name[i] != '='; i++);
    if (str[2] != NULL)
        i += my_strlen(str[2]);
    char *env = malloc(sizeof(char) * (i + 2));
    for (; tmp->name[j] != '='; j++)
        env[j] = tmp->name[j];
    env[j] = '=', j++;
    if (str[2] != NULL) {
        for (int k = 0; str[2][k] != '\0'; k++, j++)
            env[j] = str[2][k];
        env[i + 1] = '\0';
    } else env[i + 1] = '\0';
    free(tmp->name);
    tmp->name = env;
}

dlist_t *my_setenv_new(dlist_t *mylist, char **str)
{
    if (str[2] == NULL) {
        char *env = malloc(sizeof(char) * my_strlen(str[1]) + 2);
        env[0] = '\0';
        env = my_strcat(env, str[1]);
        env = my_strcat(env, "=");
        env[my_strlen(str[1]) + 1] = '\0';
        mylist = push_back_list(mylist, env);
        free(env);
        return (mylist);
    }
    int len = my_strlen(str[1]) + my_strlen(str[2]) + 2;
    char *env = malloc(sizeof(char) * len);
    env[0] = '\0';
    env = my_strcat(env, str[1]);
    env = my_strcat(env, "=");
    env = my_strcat(env, str[2]);
    env[len - 1] = '\0';
    mylist = push_back_list(mylist, env);
    free(env);
    return (mylist);
}

void my_setenv(dlist_t *mylist, char **str)
{
    int i = 0;
    for (; str[i] != NULL; i++);
    if (i > 3) {
        my_printf("setenv: Too many arguments.\n");
        return;
    } else if (i == 1) {
        print_list(mylist);
        return;
    } if (my_str_isalpha(str[1]) == 0)
        my_printf("setenv: Variable name must contain "
                    "alphanumeric characters.\n");
    dlist_node_t *tmp = mylist->begin;
    while (i >= 2 && tmp != NULL) {
        if (my_strncmp(tmp->name, str[1], my_strlen(str[1]) - 1) == 0) {
            my_setenv_replace(tmp, str);
            return;
        }
        tmp = tmp->next;
    } mylist = my_setenv_new(mylist, str);
}

void put_env_to_the_end(dlist_node_t *tmp)
{
    char *swap;
    while (tmp->next != NULL) {
        swap = tmp->name;
        tmp->name = tmp->next->name;
        tmp->next->name = swap;
        tmp = tmp->next;
    }
}

void my_unsetenv(dlist_t *mylist, char **str)
{
    if (str[1] == NULL)
        my_printf("unsetenv: Too few arguments.\n");
    dlist_node_t *tmp = NULL;
    for (int i = 0; str[i] != NULL; i++) {
        tmp = mylist->begin;
        while (tmp != NULL) {
            if (my_strncmp(str[i], tmp->name, my_strlen(str[i]) - 1) == 0
                && tmp->name[my_strlen(str[i])] == '=') {
                put_env_to_the_end(tmp);
                pop_back_list(mylist);
            }
            tmp = tmp->next;
        }
    }
}