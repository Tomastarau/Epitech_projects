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

char *my_strcat(const char *dest, char const *src);

int my_strlen(char const *str);

int my_put_nbr(int nb);

int my_putnbr_base(int nb, char const *base);

int my_strcmp(char const *s1, char const *s2);

char  *my_strncpy(char *dest, char const *src, int n);

char  *my_strcpy(char *dest, char const *src);

#endif
