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

Test(hidenp, normal_string) {
    char *expected = "1\n2\n";
    fazzbizz(1, 2);
    cr_assert_stdout_eq_str(expected);
}
