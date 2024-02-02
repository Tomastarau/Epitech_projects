/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** task01
*/

char  *my_strcpy(char *dest, char const *src)
{
    char *dest_start = dest;
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return dest_start;
}
