/*
** EPITECH PROJECT, 2023
** lemintest
** File description:
** str_to_word_arr
*/

#include <stdlib.h>
#include "../include/str_utils.h"

static int get_words_count(char const *str, char delim)
{
    int ret = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == delim && str[i + 1] != delim)
            ret++;

        if (i == 0 && str[i] != delim)
            ret++;
    }

    return ret;
}

char **str_to_word_array(char const *str, char delim)
{
    int words_count = get_words_count(str, delim);
    char **ret = malloc(8 * (words_count + 1));
    int orig_len = str_len(str);
    int start_pos = 0, end_pos = 0, idx = 0;

    for (; end_pos < orig_len; idx++) {
        for (; str[end_pos] != delim && end_pos < orig_len; end_pos++);

        ret[idx] = malloc(end_pos - start_pos + 1);
        strn_cpy(ret[idx], &str[start_pos], end_pos - start_pos);
        ret[idx][end_pos - start_pos] = 0;

        start_pos = end_pos + 1;
        end_pos = start_pos;
    }

    ret[words_count] = 0;
    return ret;
}
