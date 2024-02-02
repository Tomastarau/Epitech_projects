/*
** EPITECH PROJECT, 2022
** find biggest square in a 2d array
** File description:
** find biggest square in 2d array
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "bsq.h"
#include "printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

int if_dot(char **tab, int row, int col, int size)
{
    int j = 0, nb_row = nb_rows(tab);
    while (j < size ) {
        if (row > nb_row || tab[row][col] != '.'){
            return 0;
        }
        col++;
        j++;
    }
    return 1;
}

int find_square(char **tab, int y, int x, int size)
{
    int i = 0, j = 0, col = x, row = y;
    int nb_row = nb_rows(tab);
    while (i < size ) {
        if (if_dot(tab, row, col, size) == 0){
            return 0;
        }
        row++;
        col = x;
        i++;
    }
    return 1;
}

int bsq(char **map)
{
    int size = 2;
    square_t square_struct;
    for (int y = 1; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != '\0'; x++) {
            if (find_square(map, y, x, size) == 0){
                continue;
            }
            square_struct.size = size;
            square_struct.x = x;
            square_struct.y = y;
            size++;
        }
    }
    fill_map(square_struct, map);
    return 1;
}

void fill_map(square_t square_struct, char **map)
{
    int i = 1, temp_x = square_struct.x, temp_y = square_struct.y;
    for (int y = 0; y < square_struct.size; y++){
        for (int x = 0; x < square_struct.size; x++){
            map[temp_y][temp_x] = 'x';
            temp_x++;
        }
        temp_x = square_struct.x;
        temp_y++;
    }
    while (i != nb_rows(map) + 1){
        my_printf("%s\n", map[i]);
        i++;
    }
}
