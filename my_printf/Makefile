##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Day10
##

NAME	=	../libmy.a

SRCS	=	my_printf.c \
		my_put_nbr.c \
		my_put_unbr.c \
		my_putchar.c \
		my_putnbr_address.c \
		my_putnbr_bin.c \
		my_putnbr_hexamaj.c \
		my_putnbr_hexamin.c \
		my_putnbr_uoctal.c \
		my_putstr.c \
		my_putstr_nonprintable.c \
		my_putnbr_addresshexa.c \

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		rm $(OBJS)

fclean:
		rm $(OBJS)
		rm $(NAME)

re: fclean all
