/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** my_sokoban
*/

#ifndef MY_SOKOBAN_H_
    #define MY_SOKOBAN_H_
    #define KNRM  "\x1B[0m"
    #define KRED  "\x1B[31m"
    #define KGRN  "\x1B[32m"
    #define KYEL  "\x1B[33m"
    #define KBLU  "\x1B[34m"
    #define KMAG  "\x1B[35m"
    #define KCYN  "\x1B[36m"
    #define KWHT  "\x1B[37m"

typedef struct sokomap_s {

    int P_x;
    int P_y;
    char *msg;
} sokomap_t;

typedef struct storage_pos_s {
    int S_x;
    int S_y;
} storage_pos_t;

void move_right(char **tab, sokomap_t *sokoban, int key);

int first_locate_player(char **tab, sokomap_t *sokoban);

int first_call_if_index_is_player(char *tab, sokomap_t *sokoban, int i);

void move_right_2(char **tab, sokomap_t *sokoban);

void move_left(char **tab, sokomap_t *sokoban, int key);

void move_left_2(char **tab, sokomap_t *sokoban);

void move_up(char **tab, sokomap_t *sokoban, int key);

void move_up_2(char **tab, sokomap_t *sokoban);

void move_down(char **tab, sokomap_t *sokoban, int key);

void move_down_2(char **tab, sokomap_t *sokoban);

void analyse_event(char **tab, sokomap_t *sokoban, int key);

int my_sokoban(char **affiche);

void show_map(char **affiche);

int my_number_of_tab(char **array_tab);

void show_map(char **affiche);

int my_sokoban(char **affiche);

sokomap_t *init_sokomap(void);

storage_pos_t **init_storage_pos(int nb_storage);

char *folder_into_1d_array(char const *filepath);

int locate_player(char **tab, sokomap_t *sokoban);

int if_index_is_player(char *tab, sokomap_t *sokoban, int i);

int locate_storage_pos(int nb_storage, char** tab, storage_pos_t *loc_storage[]);

int if_index_is_storage(char *tab);

int number_of_storage(char **tab);

int my_number_of_tab(char **array_tab);
#endif /* !MY_SOKOBAN_H_ */
