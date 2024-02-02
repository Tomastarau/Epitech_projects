/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** task03
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    int max_len = my_strlen(str) / 2;
    char temp;
    while (i < max_len){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i = i + 1;
        j = j - 1;
    }
    return (str);
}
