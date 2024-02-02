/*
** EPITECH PROJECT, 2022
** concat param
** File description:
** cacatenante parameters
*/
#include <stdlib.h>

int my_strlen(char const *str);

int my_putstr(char const *str);

char *my_strcat(char *dest, char const *src);

char *concat_params(int argc ,char **argv)
{
    char *str;
    int i;
    int taillmem = 0;
    while (i != argc){
        taillmem = taillmem + my_strlen(argv[i]) + 1;
        i = i + 1;
    }
    str = malloc(sizeof(char) * taillmem);
    i = 0;
    while (i < argc - 1){
        my_strcat(str,  argv[i]);
        my_strcat(str, "\n");
        i = i + 1;
    }
    my_strcat(str, argv[i]);
    my_strcat(str, "\0");
    return (str);
}
