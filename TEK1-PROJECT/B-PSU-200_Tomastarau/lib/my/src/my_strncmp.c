/*
** EPITECH PROJECT, 2022
** temp
** File description:
** temp
*/

#include <stdio.h>

int my_strlen(const char *str);

int my_strncmp(char const *s1, char const *s2, int n)
{
    int str1 = 0;
    int str2 = 0;
    int i = 0;
    while (i < n && s1[i] != '\0' && s2[2] != '\0'){
        str1 = str1 + s1[i];
        str2 = str2 + s2[i];
        i = i + 1;
    }
    if (str1 == str2){
        return (0);
    }
    if (str1 < str2){
        return (str1 - str2);
    } else {
        return (str1 - str2);
    }
}
