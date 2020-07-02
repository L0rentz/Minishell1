/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_execve
*/

#include "my.h"

int is_exec(char **str)
{
    int check = 0;
    for (int i = 0; str[0][i] != '\0'; i++) {
        if (str[0][i + 1] == '\0')
            break;
        if ((str[0][i] == '.' && str[0][i + 1] == '/') || str[0][i] == '/')
            check = 1;
    }
    if (check == 0)
        return (0);
    struct stat fileStats;
    stat(str[0], &fileStats);
    if (S_ISREG(fileStats.st_mode) == 1) {
        check++;
    } if (S_ISDIR(fileStats.st_mode) == 1) {
        exec_error();
        return (2);
    } if (check == 2)
        return (1);
    return (0);
}

char **find_path(char **envp)
{
    int i = 0;
    for (; envp[i] != NULL; i++) {
        if (my_strlen(envp[i]) >= 4 && my_strncmp(envp[i], "PATH", 3) == 0)
            break;
    }
    char **path = my_path_to_word_array(envp[i]);
    return (path);
}

int find_command(char *path, int *pid, char **str, char **envp)
{
    DIR *Dir = opendir(path);
    struct dirent *Dirent;
    int error = 0;
    while (Dir != NULL && (Dirent = readdir(Dir)) != NULL)
        if (my_strcmp(str[0], Dirent->d_name) == 0) {
            char *first = malloc(sizeof(char) * my_strlen(path) +
                my_strlen(Dirent->d_name) + 2);
            first[0] = '\0', first = my_strcat(first, path);
            first = my_strcat(first, "/");
            first = my_strcat(first, Dirent->d_name);
            *pid = fork();
            if (*pid == 0) execve(first, str, envp);
            free(first);
            waitpid(*pid, &error, 0);
            if (WIFSIGNALED(error) == 1) print_error(error);
            closedir(Dir);
            return (-1);
        }
    closedir(Dir);
    return (0);
}

void free_double_array(char **envp, char **path)
{
    for (int i = 0; path != NULL && path[i] != NULL; i++) free(path[i]);
    free(path);
    for (int i = 0; envp[i] != NULL; i++) free(envp[i]);
    free(envp);
}

void my_execve(char **str, int *status, int *pid, dlist_t *mylist)
{
    int check = is_exec(str);
    if (check == 1) {
        *pid = fork();
        if (*pid == 0) {
            char **envp = env_linked_list_to_tab_array(mylist);
            execve(*str, str, envp);
            for (int i = 0; envp[i] != NULL; i++) free(envp[i]);
            free(envp);
        } waitpid(*pid, status, 0);
        if (WIFSIGNALED(*status) == 1) print_error(*status);
        return;
    } char **envp = env_linked_list_to_tab_array(mylist);
    char **path = find_path(envp);
    for (int i = 1; path != NULL && path[0] != NULL && path[i] != NULL; i++)
        if (find_command(path[i], pid, str, envp) == -1) {
            check = 1;
            break; }
    free_double_array(envp, path);
    if (check == 0) my_printf("%s: Command not found.\n", str[0]);
}