/*
** EPITECH PROJECT, 2023
** solo stumper 2
** file description:
** solo stumper 2 functions
*/

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include "my_printf.h"
#include "my.h"

static int puterror(char const* str, int returnCode) {
    write(2, str, my_strlen(str));
    return returnCode;
}

static verify(int compteur, char const* str1) {
    int writeExceptions = 0;

    if (!str1)
        return RETURN_ERROR;
    if (compteur == my_strlen(argv[1])){
        writeExceptions = write(STDOUT, "1\n", 2)
    } else {
        writeExceptions = write(STDOUT, "0\n", 2)
    }
    if (writeExceptions != 0)
        return RETURN_ERROR;
    return RETURN_SUCCESS;
}

static int hidenp(char *argv[])
{
    int i = 0;
    int compteur = 0;
    int j = 0;
    int len_haystack = my_strlen(argv[2]);
    if (!argv || !argv[1] || !argv[2])
        return puterror("Invalid pointers", RETURN_ERROR);
    if (len_haystack == RETURN_FAILURE)
        return puterror("Error in strlen function", RETURN_ERROR);
    while (i < len_haystack) { //TODO check for string end (argv[1])
        if (argv[1][j] == argv[2][i]) {
            compteur++;
            j++;
        }
        i++;
    }
    return verify(compteur, argv[1]);
}
