/*
** EPITECH PROJECT, 2024
** mul_div
** File description:
** mul_div
*/

#include <stdio.h>
#include "mul_div.h"

void mul_div_long(int a, int b, int *mul, int *div)
{
    *mul = a * b;
    if (b == 0) {
        *div = 42;
    } else {
        *div = a / b;
    }
    return;
}

void mul_div_short(int *a, int *b)
{
    int original_a = *a;

    *a = (*a * *b);
    if (*b == 0) {
        *b = 42;
    } else {
        *b = original_a / *b;
    }
}
