/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_cd
*/

#include "my.h"

int len_env(char *name)
{
    int i = 0;
    for (; name[i] != '='; i++);
    i++;
    return (i);
}

int my_cd_neg_no_arg(dlist_node_t **tmp, char **str)
{
    while (str[1] == NULL && *tmp != NULL) {
        if (my_strncmp((*tmp)->name, "HOME", 3) == 0) {
            chdir(&(*tmp)->name[len_env((*tmp)->name)]);
            return (errno);
        } *tmp = (*tmp)->next;
    } if (str[1] == NULL)
        return (errno = -5);
    while (str[1] != NULL && str[1][0] == '-' && my_strlen(str[1]) == 1
    && *tmp != NULL) {
        if (my_strncmp((*tmp)->name, "OLDPWD", 3) == 0) {
            chdir(&(*tmp)->name[len_env((*tmp)->name)]);
            return (errno);
        } *tmp = (*tmp)->next;
    } if (str[1] != NULL && str[1][0] == '-' && my_strlen(str[1]) == 1)
        return (errno = 2);
    if (str[1] != NULL)
        chdir(str[1]);
    return (errno);
}

void my_cd(dlist_t *mylist, char **str, char **prompt)
{
    errno = 0;
    dlist_node_t *tmp = mylist->begin;
    if (str[1] != NULL && str[2] != NULL) {
        my_printf("cd: Too many arguments.\n");
        return;
    } errno = my_cd_neg_no_arg(&tmp, str);
    if (errno == ENOTDIR) {
        my_printf("%s: Not a directory.\n", str[1]);
        return;
    } if (errno == ENOENT || errno == -5) {
        if (str[1] != NULL) my_printf("%s: No such file or directory.\n",
                str[1]);
        else if (errno != -5) my_printf("%s: No such file or directory.\n",
            &tmp->name[len_env(tmp->name)]);
        else my_printf("HOME: No such file or directory.\n", str[1]);
        return;
    } if (str[1] != NULL) { char cwd[200];
        getcwd(cwd, sizeof(cwd)), update_pwd_prompt(mylist, cwd);
    } else update_pwd_prompt(mylist, &tmp->name[len_env(tmp->name)]);
    free(*prompt), *prompt = find_pwd_prompt(mylist);
}