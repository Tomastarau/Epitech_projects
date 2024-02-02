/*
** EPITECH PROJECT, 2022
** my str isnum
** File description:
** task
*/

#include <unistd.h>
#include "my.h"

int my_str_isnum(char const * str)
{
    int i = 0;
    if (my_strlen(str) == 0){
        return (1);
    }
    while (i < my_strlen(str)){
        if (str[i] >= '0' && str[i] <= '9' || str[i] == '-' &&
        str[i + 1] >= '0' || str[i] == '-' && str[i + 1] <= '9'){
            i = i + 1;
        } else {
            return (0);
        }
    }
    return (1);
}
