##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC		=	src/main.c			\
			src/rush3.c			\
			src/my_put_nbr.c		\
			src/my_putstr.c		\
			src/my_putchar.c

OBJ		=	$(SRC:.c=.o)

NAME		=	rush3

CPPFLAGS	=	-I../include


all:	$(NAME)

$(NAME):	 $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
