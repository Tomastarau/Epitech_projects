/*
** EPITECH PROJECT, 2022
** bsq.h
** File description:
** bsq.h
*/

#ifndef BSQ_H_
    #define BSQ_H_

int my_get_nbr(char *valeur);

int nb_rows(char ** tableau);

int nb_column(char ** tableau);

char *folder_into_1d_array(char const *filepath);

int bsq(char **map);

void create_map(char *taille, char *pattern);

int check_square(int start_i, int start_y, int size, char *tab[]);

typedef struct square_s{
    int x;
    int y;
    int size;
}square_t;

void fill_map(square_t square_struct, char **map);

int find_square(char **tab, int y, int x, int size);

#endif /* !BSQ_H_ */
