/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <stdio.h>

char * my_strlowcase(char *str);

char * my_strupcase(char *str);

char *my_strcapitalize(char *str);

int my_strcmp(char const *s1, char const *s2);

int my_strncmp(char const *s1, char const *s2, int n);

int my_str_isprintable(char const *str);

int main(void)
{
    char str1[] = "ABAampsnbcba,?zfiezhv;:!::\\  ://eifzejgiop";
    printf("%d\n", my_str_isprintable(str1));
    return (0);
}
