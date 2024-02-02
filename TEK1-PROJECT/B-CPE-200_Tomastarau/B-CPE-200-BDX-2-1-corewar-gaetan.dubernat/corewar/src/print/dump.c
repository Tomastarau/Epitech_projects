/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** dump functions
*/

/* LOCAL INCLUDES */
#include "macro.h"
#include "corewar.h"
#include "op.h"
#include "lib.h"
#include "my_printf.h"

int print_champ_registers(champion_t *champ)
{
    if (champ == NULL)
        return ERROR;
    for (int i = 0; i < REG_NUMBER; i++) {
        if (i < 10)
            my_printf("R%d  : %d\n", i, champ->registers[i]);
        else
            my_printf("R%d : %d\n", i, champ->registers[i]);
    }
    return SUCCESS;
}

int dump_arena(char *arena)
{
    static const char hex_tab[] = "0123456789ABCDEF";
    int line_counter = 0;

    if (arena == NULL) {
        my_put_strerr("ERROR (dump_arena) : arena == NULL.\n");
        return ERROR;
    }
    for (int i = 0; i < MEM_SIZE; i++) {
        my_putchar(hex_tab[((unsigned char)arena[i]) / 16]);
        my_putchar(hex_tab[((unsigned char)arena[i]) % 16]);
        line_counter++;
        if (line_counter % 32 == 0) {
            line_counter = 0;
            my_putchar('\n');
        } else {
            my_putchar(' ');
        }
    }
    return SUCCESS;
}

int dump_champion_body(champion_t *champ)
{
    static const char hex_tab[] = "0123456789ABCDEF";
    int line_counter = 0;

    if (champ == NULL || champ->body == NULL) {
        my_put_strerr("ERROR (dump_champion_body) : champ == NULL.\n");
        return ERROR;
    }
    for (size_t i = 0; i < champ->body_size; i++) {
        my_putchar(hex_tab[((unsigned char)champ->body[i]) / 16]);
        my_putchar(hex_tab[((unsigned char)champ->body[i]) % 16]);
        line_counter++;
        if (line_counter % 32 == 0) {
            line_counter = 0;
            my_putchar('\n');
        }
        if (i != (champ->body_size - 1))
            my_putchar(' ');
    }
    my_putchar('\n');
    return SUCCESS;
}
