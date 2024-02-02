##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##

TEST_NAME = unit_tests

SRC = 	../ex01/mul_div.c	\
		../ex02/concat.c

TEST_SRC = 	tests_mul_div_long.c	\
			tests_mul_div_short.c	\
			tests_concat_strings.c

OBJ = $(SRC:.c=.o)
TEST_OBJ = $(TEST_SRC:.c=.o)

CFLAGS = -Wall -Wextra -std=gnu17 -I../ex01
TEST_FLAGS = -lcriterion

$(TEST_NAME): $(OBJ) $(TEST_OBJ)
	gcc -o $(TEST_NAME) $(OBJ) $(TEST_OBJ) $(TEST_FLAGS)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TEST_OBJ)
	rm -f *~

fclean: clean
	rm -f $(TEST_NAME)
	rm -f *.gcda *.gcno

re: fclean $(TEST_NAME)

.PHONY: clean fclean re test

test: $(TEST_NAME)
	./$(TEST_NAME)