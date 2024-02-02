/*
** EPITECH PROJECT, 2024
** test
** File description:
** tests_mul_div_short
*/

#include <criterion/criterion.h>
#include "../ex02/concat.h"
#include <assert.h>
#include <string.h>

Test(concat_test, test_concat_strings) {
    char *res;
    const char *str1 = "Hello, ";
    const char *str2 = "World!";

    concat_strings(str1, str2, &res);

    cr_assert_not_null(res, "Resulting string is NULL");
    cr_expect_str_eq(res, "Hello, World!", "Concatenated string did not match \
expected result");

    free(res);  // Important to free the memory allocated in concat_strings
}