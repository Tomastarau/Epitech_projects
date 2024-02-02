/*
** EPITECH PROJECT, 2024
** test
** File description:
** tests_mul_div_long
*/

#include <criterion/criterion.h>
#include "../ex01/mul_div.h"

// Prototype of the function to be tested
void mul_div_long(int a, int b, int *mul, int *div);

Test(mul_div_long, normal_operation) {
    int mul, div;
    mul_div_long(6, 3, &mul, &div);
    cr_assert_eq(mul, 18, "Expected product was 18, but got %d", mul);
    cr_assert_eq(div, 2, "Expected division result was 2, but got %d", div);
}

Test(mul_div_long, division_by_zero) {
    int mul, div;
    mul_div_long(5, 0, &mul, &div);
    cr_assert_eq(mul, 0, "Expected product was 0, but got %d", mul);
    cr_assert_eq(div, 42, "Expected division result was 42, but got %d", div);
}

Test(mul_div_long, negative_numbers) {
    int mul, div;
    mul_div_long(-4, -2, &mul, &div);
    cr_assert_eq(mul, 8, "Expected product was 8, but got %d", mul);
    cr_assert_eq(div, 2, "Expected division result was 2, but got %d", div);
}
