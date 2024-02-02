/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"


void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf1, print_a_string, .init = redirect_all_std){
    my_printf("%s", "coucou");
    cr_assert_stdout_eq_str("coucou");
}

Test(my_printf2, print_a_long_string, .init = redirect_all_std){
    my_printf("%s", "coucou c'est moi je m'appelle BENJI");
    cr_assert_stdout_eq_str("coucou c'est moi je m'appelle BENJI");
}

Test(my_printf3, print_a_number, .init = redirect_all_std){
    my_printf("%d", 188);
    cr_assert_stdout_eq_str("188");
}

Test(my_printf4, print_a_long_number, .init = redirect_all_std){
    my_printf("%d", 1885595);
    cr_assert_stdout_eq_str("1885595");
}

Test(my_printf5, print_a_negative_number, .init = redirect_all_std){
    my_printf("%d", -188);
    cr_assert_stdout_eq_str("-188");
}

Test(my_printf6, print_a_negative_long_number, .init = redirect_all_std){
    my_printf("%d", -1885595);
    cr_assert_stdout_eq_str("-1885595");
}

Test(my_printf7, print_a_char, .init = redirect_all_std){
    my_printf("%c", 'f');
    cr_assert_stdout_eq_str("f");
}

Test(my_printf8, print_a_char_, .init = redirect_all_std){
    my_printf("%c", 'fa');
    cr_assert_stdout_eq_str("a");
}

Test(my_printf9, print_a_number, .init = redirect_all_std){
    my_printf("%i", 188);
    cr_assert_stdout_eq_str("188");
}

Test(my_printf10, print_a_long_number, .init = redirect_all_std){
    my_printf("%i", 1885595);
    cr_assert_stdout_eq_str("1885595");
}

Test(my_printf11, print_a_number_unisgned, .init = redirect_all_std){
    my_printf("%i", -188);
    cr_assert_stdout_eq_str("-188");
}

Test(my_printf12, print_a_long_number_unsigned, .init = redirect_all_std){
    my_printf("%i", -1885595);
    cr_assert_stdout_eq_str("-1885595");
}

Test(my_printf13, print_a_number_unisgned, .init = redirect_all_std){
    my_printf("%u", 188);
    cr_assert_stdout_eq_str("188");
}

Test(my_printf14, print_a_long_number_unsigned, .init = redirect_all_std){
    my_printf("%u", 1885595);
    cr_assert_stdout_eq_str("1885595");
}

Test(my_printf15, print_a_octal_base_nbr, .init = redirect_all_std){
    my_printf("%o", 188);
    cr_assert_stdout_eq_str("274");
}

Test(my_printf16, print_a_long_octal_base_nbr, .init = redirect_all_std){
    my_printf("%o", 888888);
    cr_assert_stdout_eq_str("3310070");
}

Test(my_printf17, print_a_hexa_base_nbr_0x, .init = redirect_all_std){
    my_printf("%p", 595);
    cr_assert_stdout_eq_str("0x253");
}

Test(my_printf18, print_a_long_hexa_base_nbr_0x, .init = redirect_all_std){
    my_printf("%p", 544555);
    cr_assert_stdout_eq_str("0x84f2b");
}

Test(my_printf19, print_a_hexa_base_nbr, .init = redirect_all_std){
    my_printf("%x", 595);
    cr_assert_stdout_eq_str("253");
}

Test(my_printf20, print_a_long_hexa_base_nbr, .init = redirect_all_std){
    my_printf("%x", 544555);
    cr_assert_stdout_eq_str("84f2b");
}

Test(my_printf21, print_a_hexa_base_nbr, .init = redirect_all_std){
    my_printf("%X", 595);
    cr_assert_stdout_eq_str("253");
}

Test(my_printf22, print_a_long_hexa_base_nbr, .init = redirect_all_std){
    my_printf("%X", 544555);
    cr_assert_stdout_eq_str("84F2B");
}

Test(my_printf23, print_a_pourcentage, .init = redirect_all_std){
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf24, print_a_long_pourcentage, .init = redirect_all_std){
    my_printf("%%%%%%%%%%%%%%");
    cr_assert_stdout_eq_str("%%%%%%%");
}
