##
## EPITECH PROJECT, 2023
## B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
## File description:
## makefile for lib
##

PREFIX 			=	src/

LIB_PREFIX 		=	src/tools/lib/

PRINTF_PREFIX 	= 	src/tools/printf/

FILES 			=	main.c										\
					check_arg.c									\
					utils/my_put_str.c							\
					utils/my_memcpy.c							\
					utils/open_file.c							\
					init/init_arena.c							\
					init/init_champions.c						\
					init/load_champions.c						\
					print/print_help.c							\

LIB				=	my_putchar.c								\
					my_putstr.c									\
					my_put_error.c								\
					my_put_nbr.c								\
					my_strlen.c									\
					my_get_nbr.c								\
					my_strcmp.c									\
					my_strncmp.c								\
					my_strcpy.c									\
					my_strncpy.c								\
					my_strdup.c									\
					str_to_word_array.c							\
					my_strcat.c									\
					array_utils.c								\
					str_utils.c									\
					my_str_isalpha.c

PRINTF 			=	int_conv.c									\
					my_printf.c

SRC				=	$(addprefix $(LIB_PREFIX), $(LIB))			\
					$(addprefix $(PRINTF_PREFIX), $(PRINTF))	\
					$(addprefix $(PREFIX), $(FILES))

OBJ				=	$(SRC:.c=.o)

NAME			=	corewar

CFLAGS 			= 	-W -Wall -Wextra -ggdb3

CPPFLAGS		=	-I./include/

all:				$(NAME)

$(NAME):			$(OBJ)
					gcc $(CFLAGS) -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
					rm -rf $(OBJ)

fclean:				clean
					rm -rf $(NAME)

re:					clean all

.PHONY: 			re fclean clean all
