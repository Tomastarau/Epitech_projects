/*
** EPITECH PROJECT, 2022
** my str cat
** File description:
** task02
*/

int my_strlen(const char *str);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int dest_len = my_strlen(dest);
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i = i + 1;
    }
    return (dest);
}
