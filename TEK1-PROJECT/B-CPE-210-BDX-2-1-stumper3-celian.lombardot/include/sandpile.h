/*
** EPITECH PROJECT, 2023
** stumper
** File description:
** sandpile
*/

#ifndef SANDPILE_H_
    #define SANDPILE_H_

    int **get_map(const char *path, const char *str);
    int drop_sand(int **map);
    int distrib_grain(int **map, int pos_x, int pos_y);
    int locate_unstability(const int **map, int *x, int *y);
    int display_tab(const int **map, const char *to_display);

#endif /* !SANPILE_H_ */
