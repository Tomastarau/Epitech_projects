/*
** EPITECH PROJECT, 2022
** str up case
** File description:
** puts every letter of every word in it in uppercase.
*/

char * my_strupcase(char *str)
{
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - 32;
        }
        i = i + 1;
    }
    return (str);
}
