/*
** EPITECH PROJECT, 2022
** my str cat
** File description:
** task02
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int dest_len = my_strlen(dest);
    int lenglobal = my_strlen(dest) + my_strlen(src);

    while (src[i] != '\0'){
        dest[dest_len + i] = src[i];
        i = i + 1;
    }
    dest[lenglobal] = '\0';
    return (dest);
}
