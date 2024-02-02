/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** task02
*/

#ifndef MY_H_
    #define MY_H_

    int my_printf(const char *restrict format, ...);

    void my_putchar(char c);

    int my_put_nbr(int nb);

    int my_putstr(char const *str);

    int my_strlen(char const *str);

    int my_put_nbr(int nb);

    int my_putnbr_base(int nb, char const *base);

    int my_strcmp(char const *s1, char const *s2);

    char  *my_strncpy(char *dest, char const *src, int n);

    int len_of_biggest_word(char **tab);

    char  *my_strcpy(char *dest, char const *src);

    char **my_str_to_word_array(char const *str);

    int len_of_word(char const *str, int i);

    int	count_word_number(char const *str);

    int is_a_character(char c);

#endif /* !MY_H_ */
