/*
** EPITECH PROJECT, 2022
** criterion tests
** File description:
** task04
*/

# include <criterion/criterion.h>
Test(my_strncpy,copy_five_characters_in_empty_array)
{
    char dest[6] = {0};
    my_strncpy (dest, "HelloWorld", 5);
    cr_assert_str_eq(dest, "Hello");
}

Test(my_strncpy, copy_string_in_empty_array)
{
    char my_dest[6] = {0};
    char dest[6] = {0};
    my_strncpy (my_dest, "Hello", 6);
    strncpy (dest, "Hello", 6);
    cr_assert_str_eq(my_dest, dest);
}

Test(my_revstr, reverse_the_string_passed_as_pramameter)
{
    char dest2[6] = {0};
    char dest3[6] = "olleh\0";
    dest2[0] = 'h';
    dest2[1] = 'e';
    dest2[2] = 'l';
    dest2[3] = 'l';
    dest2[4] = 'o';
    dest2[5] = '\0';
    my_revstr (dest2);
    cr_assert_str_eq (dest2, dest3);
}
