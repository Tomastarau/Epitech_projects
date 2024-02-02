/*
** EPITECH PROJECT, 2022
** my strndup
** File description:
** strndup
*/
#include <stdio.h>

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strndup(char const *src, int n)
{
    int len = my_strlen(src);
    char *dest;
    int i = 0;

    dest = malloc(sizeof(char) * n + 1);
    while (i < n){
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}

int main(void)
{
    char strn[] = "aaaaaaarf";
    printf("%d\n", my_strndup(strn, 5));
}
