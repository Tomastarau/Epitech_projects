##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC		=	nom_des_fichiers.c

OBJ		=	$(SRC:.c = .o)

NAME		=	nom_du_fichier_que_tu_créer

LDFLAGS		=	-L ../lib

LDLIBS		=	-lmy

CPPFLAGS	=	-I ../include

LIB		=	../lib/libmy.a

all:	$(NAME)

$NAME:		$(LIB) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LIDLIBS)

$(LIBS):
	make -C ../lib/my

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re	fclean all

.PHONY: all clean fclean re
