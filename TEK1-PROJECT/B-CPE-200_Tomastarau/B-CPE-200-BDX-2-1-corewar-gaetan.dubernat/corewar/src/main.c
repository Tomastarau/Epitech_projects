/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** main function
*/

/* LOCAL INCLUDES */
#include "macro.h"
#include "corewar.h"
#include "op.h"
#include "lib.h"

int get_nb_champ(char **argv)
{
    int count = 0;

    for (int i = 1; argv[i]; i++) {
        size_t length = my_strlen(argv[i]);
        if (length > 4 && (my_strcmp((argv[i] + (length - 4)), ".cor") == 0))
            count++;
    }
    return count;
}

static int init_all(char **argv, corewar_t *core, instruction_t *instru)
{
    int nb_champs = 0;

    if (core == NULL || instru == NULL)
        return ERROR;
    nb_champs = get_nb_champ(argv);
    if (nb_champs == 0) {
        my_put_strerr("Error : no champ.\n");
        return ERROR;
    }
    if (init_core(core, nb_champs) == ERROR)
        return ERROR;
    if (init_instruction(instru) == ERROR)
        return ERROR;
    if (init_arena(core) == ERROR)
        return ERROR;
    if (init_champions(core, argv) == ERROR)
        return ERROR;
    return SUCCESS;
}

static void free_all(corewar_t *core)
{
    if (core == NULL)
        return;
    if (core->arena != NULL) {
        free(core->arena);
        core->arena = NULL;
    }
}

int main(int argc, char **argv)
{
    corewar_t *core = malloc(sizeof(corewar_t));
    instruction_t *instru = malloc(sizeof(instruction_t));

    core->dump_cycles = -1;
    if (core == NULL || instru == NULL)
        return EPITECH_ERROR;
    if (check_args(core, argc, argv) == ERROR)
        return EPITECH_ERROR;
    if (init_all(argv, core, instru) == ERROR)
        return EPITECH_ERROR;
    if (load_champions(core) == ERROR)
        return EPITECH_ERROR;
    if (dump_arena(core->arena) == ERROR)
        return EPITECH_ERROR;
    free_all(core);
    return SUCCESS;
}
