/*
** EPITECH PROJECT, 2023
** map_handling
** File description:
** map_handling
*/

#include "my.h"
#include "my_printf.h"
#include "my_navy.h"

int fill_map_boat(char **map, int i, int letter_pos, char **array_pos)
{
    int x = 0, y = 1, pos_chiffre = char_to_int(array_pos[i][letter_pos + 1]);
    int pos_lettre = letter_to_number(array_pos[i][letter_pos]);
    while ((map[char_to_int(array_pos[i][letter_pos + 4]) + 1][letter_to_number\
(array_pos[i][letter_pos + 3])]) != array_pos[i][0]){
        if (pos_lettre < letter_to_number(array_pos[i][letter_pos + 3]))
                x = x + 2;
        if (pos_lettre > letter_to_number(array_pos[i][letter_pos + 3]))
                x = x - 2;
        if (pos_chiffre + 1 < char_to_int(array_pos[i][letter_pos + 4]) + 1)
                y = y + 1;
        if (pos_chiffre + 1 > char_to_int(array_pos[i][letter_pos + 4]) + 1)
                y = y - 1;
        if (map[pos_chiffre + y][pos_lettre + x] == '.'){
            map[pos_chiffre + y][pos_lettre + x] = array_pos[i][0];
        } else {
            return 84;
        }
    }
    return 0;
}

int add_map_boat(char *pos_folder, char** map)
{
    char *pos = folder_into_1d_array(pos_folder);
    char **array_pos = my_str_to_word_array(pos);
    int i = 0, x = 0, y = 1, letter_pos = 2;
    while (array_pos[i] != NULL){
        if (fill_map_boat(map, i, letter_pos, array_pos) != 84 && map[char_to_i\
nt(array_pos[i][letter_pos + 1]) + y][letter_to_number(array_pos[i][letter_pos]\
) + x] == '.') {
            map[char_to_int(array_pos[i][letter_pos + 1]) + y]\
[letter_to_number(array_pos[i][letter_pos]) + x] = array_pos[i][0];
            fill_map_boat(map, i, letter_pos, array_pos);
            i = i + 2;
            x = 0;
            y = 1;
        } else {
            return 84;
        }
    }
    return 0;
}

int char_to_int(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    else
        return -1;
}

void print_tab(char **tab)
{
    int i = 0;
    while (tab[i] != NULL){
        my_printf("%s\n", tab[i]);
        i++;
    }
}

int letter_to_number(char letter)
{
    int number = 0;
    int i = 64;
    while (i != letter){
        number++;
        i++;
    }
    return number * 2;
}
