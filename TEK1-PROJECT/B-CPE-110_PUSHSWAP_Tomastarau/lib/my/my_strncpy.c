/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** task02
*/

int my_strlen(char const *str);

char  *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    while (src[i] != '\0'){
        if (i == n){
            return dest;
        }
        dest[i] = src[i];
        i++;
    }
    if (n > i){
        dest[i] = '\0';
        i++;
    }
    return (dest);
}
