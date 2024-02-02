/*
** EPITECH PROJECT, 2022
** my_lib header
** File description:
** all prototypes
*/

#ifndef MY_LIB_
    #define MY_LIB_

    char *my_strncmp(char *dest, char const *src, int n);
    char *my_strstr(char *str, char const *to_find);
    int my_getnbr(char const *str);
    char **my_str_to_word_array(char *str);
    int my_strlen(char const *str);
    char *my_strncpy(char *dest, char const *src, int n);
    int free_str_tab(char **str);

#endif /* MY_LIB_ */
