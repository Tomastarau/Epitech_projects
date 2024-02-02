/*
** EPITECH PROJECT, 2023
** stumper4 functions
** File description:
** stumper4 fonction
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int find_letter(char *str, int i, int j)
{
    char* replace_num = "012345";
    char* replace_char = "oiueay";
    char* replace_char_2 = "OIUEAY";
    if (!replace_num || !replace_char || !replace_char_2 || !str)
        return 84;
    while (j != 6){
        if (replace_char[j] == str[i] || replace_char_2[j] == str[i]){
            str[i] = replace_num[j];
            break;
        }
        j++;
    }
    return 0;
}

int geek_name(char* str)
{
    int i = 0;
    int j = 0;
    if (!str)
        return 84;
    while (i != my_strlen(str)){
        if (find_letter(str, i, j) == 84)
            return 84;
        if (i > 0 && str[i] >= 'A' && str[i] <= 'Z' && str[i - 1] >= 'A' \
&& str[i - 1] <= 'Z')
            str[i] = str[i] + 32;
        if (i == 0 || (i > 0 && str[i] >= 'a' && str[i] <= 'z' && str[i - 1] \
>= 'a' && str[i - 1] <= 'z') || (i > 0 && str[i - 1] \
<= ' ') || (str[i - 1] > '~' && str[i] >= 'a' && str[i] <= 'z'))
            str [i] = str[i] - 32;
        j = 0;
        i++;
    }
    write(1, str, my_strlen(str));
    write(1, "\n", 2);
    return 0;
}
