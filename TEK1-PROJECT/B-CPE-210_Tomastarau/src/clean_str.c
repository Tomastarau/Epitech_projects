/*
** EPITECH PROJECT, 2023
** solo stumper 1
** File description:
** clean_str
*/

#include "../include/my.h"
#include "../include/my_printf.h"
#include <stddef.h>
#include <unistd.h>

void clean_str(char *argv[])
{
    char **tab = my_str_t
    int len_tab = 0;
    for (int i = 0; tab[i] != NULL; i++){
        len_tab++;
    }
    for (int j = 0; j < (len_tab - 1); j++){
        my_printf("%s ", tab[j]);
    }
    my_printf("%s\n", tab[len_tab - 1]);
}

int main(int argc, char *argv[])
{
    if (argc == 2 && my_str_isprintable(argv[1]) == 1){
        clean_str(argv);
    }
    if (argc > 2 || (argc == 2 && my_str_isprintable(argv[1]) == 0)){
        write(2, "Error\n", 7);
        return 84;
    }
    if (argc == 1){
        return 0;
    } else {
        return 0;
    }
}
