/*
** EPITECH PROJECT, 2022
** Search_flags.c
** File description:
** Search for flags
*/

#include "../include/printf.h"
#include "../include/my.h"
#include <unistd.h>
#include <stdio.h>

int find_next_flag(const char *format, va_list list, int i)
{
    int iflag = 0;
    int char_search_flag = 0;

    if (format != NULL){
        while (FLAGS[iflag].flag != format[i] && iflag < 10) {
            iflag++;
        }
    char_search_flag = FLAGS[iflag].function(list);
    return char_search_flag;
    }else{
        write(2, "No arg", 6);
        return 84;
    }
}
