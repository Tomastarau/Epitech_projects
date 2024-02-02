/*
** EPITECH PROJECT, 2023
** n4s.h
** File description:
** n4s.h
*/

#ifndef N4S_H_
    #define N4S_H_

    #include "structures.h"
    #include <stdio.h>

    //str -> word array
    char **my_str_to_word_array_minishell(char const *str, char separator);

    //speed and degree
    float get_speed(data_lidar_t lidar);
    float get_rotation(data_lidar_t lidar);

    //array_utils
    void print_tab(char **tab);
    int len_tab(char **tab);

#endif /* !N4S_H_ */
