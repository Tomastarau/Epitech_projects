/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-BSQ-jules.fradin
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

// int bsq(int const argc, char * const * const argv);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(unit_tests, my_test, .init=redirect_all_std)
{
    FILE *original = fopen("src/example4_solved.txt", "r");
    bsq(2, (char *[]) {"", "src/example4.txt"});
    cr_assert_stdout_eq(original);
}
