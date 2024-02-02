/*
** EPITECH PROJECT, 2022
** Printf_s.c
** File description:
** Flag "s" for my_printf.c
*/

#include "../include/printf.h"
#include "../include/my.h"
#include <unistd.h>

int printf_s(va_list ap)
{
    char * p = va_arg(ap, char*);
    int char_flag = 0;

    if (p != NULL){
        char_flag = my_strlen(p);
        my_putstr(p);
        return char_flag;
    }else{
        write(2, "No arg", 6);
        return 84;
    }
}
