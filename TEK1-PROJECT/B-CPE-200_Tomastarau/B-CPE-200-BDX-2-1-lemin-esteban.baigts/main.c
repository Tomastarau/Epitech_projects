/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** main
*/

#include "include/anthill.h"
#include "include/anthill_parse.h"

int main(int argc, char *argv[])
{
    context_t *ctx = create_context();
    if (parse_anthill(ctx) == -1) {
        destroy_anthill(ctx);
        return 84;
    }

    display_anthill(ctx);
    destroy_anthill(ctx);
    return 0;
}
