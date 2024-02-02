/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-BSQ-jules.fradin
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "ginger.h"
#include "my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(unit_tests, my_test, .init=redirect_all_std)
{
    ginger_t *ginger_stats = malloc(sizeof(ginger_t));
    int func_return = retrieve_args(5, (char *[]) {"", "-f", "map.txt", "-m", "2"}, ginger_stats);
    free_str_tab(ginger_stats->map);
    free(ginger_stats);
    cr_assert_eq(0, func_return);
}
