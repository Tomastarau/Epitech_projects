/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** str_utils
*/

#ifndef STR_UTILS_H
    #define STR_UTILS_H

    char *str_dup(char const *src);
    int str_cmp(char const *s1, char const *s2);
    char *str_chr(char const *str, int ch);
    char *str_cpy(char *dest, char const *src);
    char *strn_cpy(char *dest, char const *src, int n);
    int str_len(char const *str);
    char **str_to_word_array(char const *str, char delim);
    int str_to_num(char const *str);

#endif // !STR_UTILS_H
