/*
** EPITECH PROJECT, 2022
** task07
** File description:
** difference btwn 2 str
*/

int my_strcmp(char const *s1, char const *s2)
{
    int it = 0;
    int res = 0;

    while (s1[it] != '\0' || s2[it] != '\0') {
        if (s1[it] - s2[it] < 0) {
            res = s1[it] - s2[it];
            return res;
        }
        if (s1[it] - s2[it] > 0) {
            res = s1[it] - s2[it];
            return res;
        }
        it++;
    }
    return 0;
}
