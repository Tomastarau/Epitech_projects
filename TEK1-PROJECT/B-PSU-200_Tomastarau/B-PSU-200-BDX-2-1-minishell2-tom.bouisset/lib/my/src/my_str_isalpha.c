/*
** EPITECH PROJECT, 2022
** my_str_isalpha
** File description:
** task
*/

#include <stdbool.h>
#include <string.h>
#include "my.h"

bool is_alpha(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int my_str_isalpha(const char *str)
{
    int i = 0;
    int len = my_strlen(str);

    if (len == 0){
        return 1;
    }

    while (i < len){
        if (!is_alpha(str[i])){
            return 0;
        }
        i++;
    }
    return 1;
}
