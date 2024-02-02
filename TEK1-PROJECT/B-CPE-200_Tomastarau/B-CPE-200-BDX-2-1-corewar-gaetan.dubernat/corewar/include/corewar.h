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
    #include <stdbool.h>

typedef struct argument {
    args_type_t type;
    int value;
} argument_t;

typedef struct instruction {
    int opcode;
    argument_t *args[MAX_ARGS_NUMBER];
} instruction_t;

typedef struct champion {
    char name[PROG_NAME_LENGTH + 1];
    int id;
    size_t file_size;
    char *body;
    size_t body_size;
    int registers[REG_NUMBER];
    int pc;
    int exec_cycle;
    int carry;
    int cycles_since_live;
    int alive;
} champion_t;

typedef struct corewar {
    char *arena;
    int nb_champs;
    champion_t **champ;
    int last_alive;
    int cycle_count;
    int dump_cycles;
} corewar_t;

    //GLOBAL
    int init_core(corewar_t *core, int nb_champs);

    //CHECK
    int check_args(corewar_t *core, int const argc, char *argv[]);
    int check_path(char const *path);
    int check_file(char const *arg);
    int set_dump_value(corewar_t *core, char *argv[], int i);

    //ARENA
    int init_arena(corewar_t *core);

    //CHAMPION
    int init_champions(corewar_t *core, char **argv);
    int read_champion(champion_t *champ, int fd);
    int load_champions(corewar_t *core);

    //INSTRUCTIONS
    int init_instruction(instruction_t *instru);
    bool exec_add(champion_t *champ, int reg1, int reg2, int reg3);
    bool exec_sub(champion_t *champ, int reg1, int reg2, int reg3);
    int exec_live(corewar_t *core, champion_t *champ);

    //PRINT
    int dump_champion_body(champion_t *champ);
    int dump_arena(char *arena);
    int print_champ_registers(champion_t *champ);

    //FREE
    void free_instruction(instruction_t *instru);
#endif
