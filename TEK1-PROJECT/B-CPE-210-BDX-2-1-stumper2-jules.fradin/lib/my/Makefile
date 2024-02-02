##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	=	my_strncmp.c \
		my_strstr.c \
        my_getnbr.c \
        my_str_to_word_array.c \
        my_strncpy.c \
        my_strlen.c \
        free_str_tab.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mkdir -p ../../include
	cp $(NAME) ../
	cp my.h ../../include

clean:
	@$(RM) -vf $(OBJ)
	@$(RM) -vf $(NAME)

fclean: clean
	## rm -f ../../include/my.h
	@$(RM) -vf ../libmy.a

re: fclean all

.PHONY:	all clean
