/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** task05
*/

#include <stdio.h>

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int str1 = 0;
    int str2 = 0;
    int i = 0;
    while (i < my_strlen(s1)){
        str1 = str1 + s1[i];
        i = i + 1;
    }
    i = 0;
    while (i < my_strlen(s2)){
        str2 = str2 + s2[i];
        i = i + 1;
    }
    if (str1 == str2){return (0);}
    if (str1 < str2){return (str1 - str2);}
    else {
        return (str1 - str2);
    }
}



