/*
** EPITECH PROJECT, 2022
** my_print_digits
** File description:
** print digits in ascending order
*/
void my_putchar(char c);

int my_print_digits(void)
{
    int a;
    a = 48;
    while (a < 58){
        my_putchar(a);
        a = a + 1;
    }
    my_putchar('\n');
    return (0);
}
