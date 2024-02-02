/*
** EPITECH PROJECT, 2024
** test
** File description:
** tests_mul_div_short
*/

#include <criterion/criterion.h>
#include "../ex01/mul_div.h"

void mul_div_short(int *a, int *b);

Test(mul_div_short, normal_operation) {
    int a = 6, b = 3;
    mul_div_short(&a, &b);
    cr_assert_eq(a, 18, "Expected product was 18, but got %d", a);
    cr_assert_eq(b, 2, "Expected division result was 2, but got %d", b);
}

Test(mul_div_short, division_by_zero) {
    int a = 5, b = 0;
    mul_div_short(&a, &b);
    cr_assert_eq(a, 0, "Expected product was 0, but got %d", a);
    cr_assert_eq(b, 42, "Expected division result was 42, but got %d", b);
}

Test(mul_div_short, negative_numbers) {
    int a = -4, b = -2;
    mul_div_short(&a, &b);
    cr_assert_eq(a, 8, "Expected product was 8, but got %d", a);
    cr_assert_eq(b, 2, "Expected division result was 2, but got %d", b);
}
