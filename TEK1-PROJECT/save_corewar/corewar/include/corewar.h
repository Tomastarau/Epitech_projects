/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** include corewar
*/


#ifndef PROJECT_H_
    #define PROJECT_H_

    #include "op.h"
    #include "utils.h"

typedef struct champion {
    char name[PROG_NAME_LENGTH + 1];
    int id;
    size_t file_size;
    char *header;
    size_t header_size;
    char *body;
    size_t body_size;
} champion_t;

typedef struct corewar {
    char *arena;
    int nb_champs;
    champion_t **champ;
} corewar_t;

    //GLOBAL
    int check_arg(int const argc, char *argv[]);

    //ARENA
    int init_arena(corewar_t *core);

    //CHAMPION
    int init_champions(corewar_t *core, char **argv);
    int load_champions(corewar_t *core);
#endif
