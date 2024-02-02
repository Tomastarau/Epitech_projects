/*
** EPITECH PROJECT, 2022
** my_evil_str
** File description:
** task04
*/

int len(char *list)
{
    int i = 0;
    while (list[i] != '\0'){
        i = i + 1;
    }
    return (i);
}

char *my_evil_str(char *str)
{
    int i = 0;
    int j = len(str) - 1;
    int max_len = len(str) / 2;
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
