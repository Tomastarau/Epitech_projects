/*
** EPITECH PROJECT, 2022
** str capitalize
** File description:
**  capitalizes the first letter of each word.
*/
char * my_strlowcase(char *str);

char *my_strcapitalize(char *str)
{
    int i = 0;
    str = my_strlowcase(str);
    if (str[i] >= 'a' && str[i] <= 'z'){
        str[i] = str[i] - 32;
    }
    while (str[i] != '\0'){
        if (str[i] == ' ' && str[i + 1] >= 'a' && str[i + 1] <= 'z'){
            str[i + 1] = str[i + 1] - 32;
        }
        i = i + 1;
    }
    return (str);
}

