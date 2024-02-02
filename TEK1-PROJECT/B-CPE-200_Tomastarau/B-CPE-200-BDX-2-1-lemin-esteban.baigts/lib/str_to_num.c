/*
** EPITECH PROJECT, 2023
** lemintest
** File description:
** str_to_num
*/

#include "../include/str_utils.h"

int str_to_num(char const *str)
{
    int idx = 0, negative_count = 0;
    long long ret = 0;
    char stop = 0;
    while (!stop) {
        if (str[idx] >= 48 && str[idx] <= 57) {
            ret = ret * 10 + (str[idx] - 48);
            stop = (str[idx + 1] < 48 || str[idx + 1] > 57)
                    || (ret > 2147483647 || ret < -2147483648);
        }

        if (str[idx] == 45) negative_count++;
        if (str[idx + 1] == 0) break;

        idx++;
    }

    if (negative_count % 2 > 0) ret *= -1;
    if (ret > 2147483647 || ret < -2147483648) return 0;
    return (int)ret;
}
