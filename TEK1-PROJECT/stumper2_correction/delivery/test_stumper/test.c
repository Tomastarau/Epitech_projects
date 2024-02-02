/*
** EPITECH PROJECT, 2023
** test
** File description:
** test stumper
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

//    category     nom du test     callback
Test(hidenp,  normal_string,  .init = redirect_all_std) {
    char *argv[] = {"./hidenp", "padinton", "padinton"};
    char *expected = "1\n";
    hidenp(argv);
    cr_assert_stdout_eq_str(expected);
}
