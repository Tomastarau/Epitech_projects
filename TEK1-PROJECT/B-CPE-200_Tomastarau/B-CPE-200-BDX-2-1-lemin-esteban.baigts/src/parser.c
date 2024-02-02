/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** parser
*/

#include "../include/parser.h"
#include "../include/lib.h"

char *parser_get_next_line(void)
{
    char *buffer = 0;
    size_t size = 0;
    while (1) {
        if (getline(&buffer, &size, stdin) == -1) {
            free(buffer);
            return 0;
        }

        if (!(buffer[0] == '#' && buffer[1] != '#'))
            break;
    }
    if (buffer != 0)
        buffer[str_len(buffer) - 1] = 0;

    if (buffer[0] != '#' && buffer[1] != '#') {
        char *comment_ptr = str_chr(buffer, '#');
        if (comment_ptr != 0)
            *comment_ptr = 0;
    }
    return buffer;
}
