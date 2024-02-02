/*
** EPITECH PROJECT, 2022
** my str is alpha num 
** File description:
** task
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_str_isalphanum(char const * str)
{
    int i = 0;
    if(my_strlen(str) == 0){
        return (1);
    }
    while(str[i] != '\0'){
        if ((str[i] >= 'A' && str[i] <= 'Z') 
	    || (str[i] >= 'a' && str[i] <= 'z')
	    || (str[i] >= '0' && str[i] <= '9'))
            i = i + 1;
        else
            return (0);
    }
    return (1);
}
