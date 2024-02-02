/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** Instruction : live
*/

/* LOCAL INCLUDES */
#include "macro.h"
#include "corewar.h"
#include "my_printf.h"

int exec_live(corewar_t *core, champion_t *champ)
{
    if (core == NULL || champ == NULL)
        return ERROR;
    champ->alive = 1;
    core->last_alive = champ->id;
    champ->cycles_since_live = 0;
    my_printf("Champion %s is alive!\n", champ->name);
    return SUCCESS;
}
