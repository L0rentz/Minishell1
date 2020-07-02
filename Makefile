##
## EPITECH PROJECT, 2019
## PSU_my_ls_2019
## File description:
## Makefile
##

NAME	=	mysh

SRCS	=	main.c \
		check_if_builtins.c \
		my_execve.c \
		my_prompt.c \
		my_cd.c \
		my_env.c \
		env_linked_list_tab.c \
		create_print_list.c \
		push_pop_clear_list.c \
		my_word_array/my_str_to_word_array.c \
		my_word_array/my_path_to_word_array.c \
		my_utils.c \
		get_next_line/get_next_line.c \
		error_handling.c \

OBJS	=	$(SRCS:.c=.o)

CFLAGS =	-lmy -L./ -Wall -Wextra -g3 -O2

CALLMAKE =	cd my_printf/ && make

all:	$(NAME)

$(NAME):	$(OBJS) $(SRCS)
		$(CALLMAKE)
		gcc -o $(NAME) $(OBJS) $(CFLAGS)
clean:
		rm $(OBJS)
		cd my_printf/ && make clean
fclean:
		rm $(NAME)
		rm $(OBJS)
		cd my_printf/ && make fclean

re: fclean all
