##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC		=	cat.c	\
			main.c	

OBJ		=	$(SRC:.c=.o)

NAME		=	cat

LDFLAGS		=	-L./../lib -lmy


CPPFLAGS	=	-I../include

LIB		=	../lib/libmy.a

all:	$(NAME)

$(NAME):		$(LIB) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS)

$(LIB):
	make -C ../lib/my

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
