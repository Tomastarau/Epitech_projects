/*
** EPITECH PROJECT, 2022
** my str len
** File description:
** len of a string
*/

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0'){
        i = i + 1;
    }
    return (i);
}
