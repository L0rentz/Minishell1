/*
** EPITECH PROJECT, 2020
** PSU_my_exec_2019
** File description:
** main
*/

#include "my.h"

int main(int argc, char **argv, char **envp)
{
    int status, check = 0;
    pid_t pid = 0;
    dlist_t *mylist = env_to_linked_list(envp);
    char **str, *gnl, *prompt = find_pwd_prompt(mylist);
    while (argc == 1 && argv[1] == NULL) {
        status = 0, check = 0, my_printf("[%s]$ ", prompt);
        gnl = get_next_line(0);
        if (gnl == NULL || my_strcmp(gnl, "exit") == 0) {
            my_printf("exit\n"), free(gnl), clear_list(mylist), free(prompt);
            return (0);
        } else str = my_str_to_word_array(gnl);
        free(gnl);
        if (str != NULL && str[0] != NULL)
            check_command(str, &check, mylist, &prompt);
        if (str != NULL && str[0] != NULL && check == 0)
            my_execve(str, &status, &pid, mylist);
        for (int i = 0; str != NULL && str[i] != NULL; i++) free(str[i]);
        free(str);
    }
}