/*
** EPITECH PROJECT, 2022
** my_str_isalpha
** File description:
** task
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_str_isalpha(char const * str)
{
    int i = 0;
    if(my_strlen(str) == 0){
        return (1);
    }
    while(i < my_strlen(str)){
        if (str[i] >= 'A' && str[i] <= 'Z'){
            i = i + 1;
        }
        if (str[i] >= 'a' && str[i] <= 'z'){
            i = i + 1;
        }else{
            return(0);
        }
    }
    return (1);
}
