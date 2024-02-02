/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** parse_anthill_links
*/

#include "../include/anthill.h"
#include "../include/lib.h"

int parse_anthill_link(context_t *ctx, char *buffer)
{
    link_node_t *link = create_link(&ctx->rooms, buffer);
    if (!link) {
        print_error("Could not parse link ", 0);
        print_error(buffer, '\n');
        return -1;
    }

    add_to_list((list_t *)(&ctx->links), link);
    return 0;
}
