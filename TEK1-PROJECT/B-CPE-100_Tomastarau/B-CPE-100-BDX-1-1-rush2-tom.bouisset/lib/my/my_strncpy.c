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
    if (n > my_strlen(src)){
        while (i < my_strlen(src)){
            dest[i] = src[i];
            i = i + 1;
        }
        while (i < n){
            dest[i] = '\0';
            i = i + 1;
        }
    }else{
        while (i != n){
            dest[i] = src[i];
            i = i + 1;
        }
        dest[i] = '\0';
    }
    return (dest);
}
