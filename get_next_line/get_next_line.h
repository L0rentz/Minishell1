/*
** EPITECH PROJECT, 2019
** GET_NEXT_LINE
** File description:
** HEADER
*/

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef READ_SIZE
#define READ_SIZE (16)
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *get_next_line(int fd);

#endif
