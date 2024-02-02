/*
** EPITECH PROJECT, 2022
** temp
** File description:
** temp
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int res = 0;
    while (str[i] != '\0' && res <= 2147483647) {
        if (str[i] >= '0' && str[i] <= '9') {
            res = res * 10 + (str[i] - '0');
        }
        i++;
    }
    return res;
}
