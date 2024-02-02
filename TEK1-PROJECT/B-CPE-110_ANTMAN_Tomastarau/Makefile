##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME	=	make

all:		$(NAME)

make:
		$(MAKE) -C	lib/my
		$(MAKE) -C	antman/
		$(MAKE)	-C	giantman/

clean:
		rm -f $(OBJ)
		$(MAKE) clean -C lib/my
		$(MAKE) clean -C antman/
		$(MAKE) clean -C giantman/

fclean: 	clean
		rm -f $(NAME)
		$(MAKE) fclean -C lib/my
		$(MAKE) fclean -C antman/
		$(MAKE) fclean -C giantman/

run_tests:

re:		fclean all
		$(MAKE) re -C antman/
		$(MAKE) re -C giantman/
