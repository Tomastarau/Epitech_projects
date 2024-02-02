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

int main(int argc, char **argv)
{
    corewar_t *core = malloc(sizeof(corewar_t));
    int nb_champ;

    if (core == NULL)
        return EPITECH_ERROR;
    if (check_arg(argc, argv) == ERROR)
        return EPITECH_ERROR;
    nb_champ = get_nb_champ(argv);
    core->nb_champs = nb_champ;
    core->champ = malloc(sizeof(champion_t*) * (nb_champ + 1));
    if (core->champ == NULL)
        return EPITECH_ERROR;
    if ((init_arena(core) == ERROR) || (init_champions(core, argv) == ERROR))
        return ERROR;
    if (load_champions(core) == ERROR)
        return ERROR;
    return SUCCESS;
}
