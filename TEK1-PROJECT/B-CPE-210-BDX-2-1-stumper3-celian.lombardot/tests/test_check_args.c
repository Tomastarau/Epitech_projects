/*
** EPITECH PROJECT, 2023
** stumper
** File description:
** test_check_args
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "macro_errors.h"
int check_args(const int argc, const char * argv[]);

void redirect_all_std (void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(check_args1, no_args){
    redirect_all_std();
    const int argc = 1;
    const char * argv1[1] = {"./project"};
    int check = 0;

    check = check_args(argc, argv1);
    cr_assert_eq(check, ERROR);
}

Test(check_args2, no_args){
    redirect_all_std();
    const int argc = 2;
    const char * argv1[] = {"./project", "args"};
    int check = 0;

    check = check_args(argc, argv1);
    cr_assert_eq(check, ERROR);
}

Test(check_args3, no_args){
    redirect_all_std();
    const int argc = 3;
    const char * argv1[] = {"./project"}, {"args"}, {"args"};
    int check = 0;

    check = check_args(argc, argv1);
    cr_assert_eq(check, ERROR);
}
