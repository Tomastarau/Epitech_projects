/*
** EPITECH PROJECT, 2022
** Struct.c
** File description:
** initiate the struc_flag_s
*/

#include "../include/printf.h"

const struct flag_s FLAGS[11] = {
    {
        flag : 'c',
        function : &printf_c
    },
    {
        flag : 's',
        function : &printf_s
    },
    {
        flag : 'd',
        function : &printf_d
    },
    {
        flag : 'i',
        function : &printf_i
    },
    {
        flag : 'o',
        function : &printf_o
    },
    {
        flag : 'u',
        function : &printf_u
    },
    {
        flag : 'x',
        function : &printf_x
    },
    {
        flag : 'X',
        function : &printf_x_up
    },
    {
        flag : '%',
        function : &printf_pourcentage
    },
    {
        flag : 'p',
        function : &printf_p
    }
};
