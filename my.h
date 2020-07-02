/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H

#include "my_printf/my_printf.h"
#include "get_next_line/get_next_line.h"

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

typedef enum
{
    false,
    true
} bool;

typedef struct dlist_node_s
{
    char *name;
    struct dlist_node_s *back;
    struct dlist_node_s *next;
} dlist_node_t, node_t;

typedef struct dlist_s
{
    unsigned int length;
    struct dlist_node_s *begin;
    struct dlist_node_s *end;
} dlist_t;

dlist_t *new_list(void);
bool is_empty_list(dlist_t *li);
dlist_node_t *new_dlist_node(char *str);
void print_list(dlist_t *li);
void print_list_rev(dlist_t *li);
dlist_t *push_back_list(dlist_t *li, char *str);
dlist_t *push_front_list(dlist_t *li, char *str);
dlist_t *pop_front_list(dlist_t *li);
dlist_t *pop_back_list(dlist_t *li);
dlist_t *clear_list(dlist_t *li);

char **my_str_to_word_array(char const *str);
char **my_path_to_word_array(char const *str);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
void my_unsetenv(dlist_t *mylist, char **str);
void my_setenv(dlist_t *mylist, char **str);
void my_execve(char **str, int *status, int *pid, dlist_t *mylist);
void check_command(char **str, int *check, dlist_t *mylist, char **prompt);
char *find_pwd_prompt(dlist_t *mylist);
void update_pwd_prompt(dlist_t *mylist, char *prompt);
void my_cd(dlist_t *mylist, char **str, char **prompt);
char **env_linked_list_to_tab_array(dlist_t *mylist);
dlist_t *env_to_linked_list(char **envp);
int my_str_isalpha(char const *str);
void print_error(int error);
void exec_error(void);

#endif
