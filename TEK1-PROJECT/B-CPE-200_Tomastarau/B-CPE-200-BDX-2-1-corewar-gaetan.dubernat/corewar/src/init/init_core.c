/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** init struct core
*/

/* LOCAL INCLUDES */
#include "macro.h"
#include "corewar.h"

int init_core(corewar_t *core, int nb_champs)
{
    if (core == NULL)
        return ERROR;
    core->last_alive = 0;
    core->nb_champs = nb_champs;
    core->champ = malloc(sizeof(champion_t*) * (nb_champs + 1));
    if (core->champ == NULL)
        return ERROR;
    core->last_alive = 0;
    core->cycle_count = 0;
    return SUCCESS;
}
