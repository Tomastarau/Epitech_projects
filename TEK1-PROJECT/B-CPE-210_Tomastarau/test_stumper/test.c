/*
** EPITECH PROJECT, 2023
** test
** File description:
** test stumper
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"
#include "../include/my_printf.h"
#include "../include/stumper.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(clean_str, normal_string) {
    char *argv[] = { "./clean_str", "hello how are you?" };
    char *expected = "hello how are you?\n";
    clean_str(argv);
    cr_assert_stdout_eq_str(expected);
}

