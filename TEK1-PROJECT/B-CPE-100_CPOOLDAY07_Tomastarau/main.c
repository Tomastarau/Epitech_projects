/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <stdio.h>

int main(void)
{
    char dest[] = "hello";
    char src[] = "worlllld";
    my_strncat(dest, src, 3);
    printf("%s\n", dest);
    return (0);
}
