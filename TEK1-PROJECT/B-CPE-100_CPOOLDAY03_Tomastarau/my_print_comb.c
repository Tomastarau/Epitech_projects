/*
** EPITECH PROJECT, 2022
** my_print_comb
** File description:
** task 05
*/

void my_putchar(char c);

int my_print_comb(void)
{
    int abc = 12;
    while (abc != 789){
        if (abc / 100 < abc / 10 % 10 && abc / 10 % 10 < abc % 10){
            my_putchar((abc / 100) + 48);
            my_putchar((abc / 10 % 10) + 48);
            my_putchar((abc % 10) + 48);
            my_putchar(',');
            my_putchar(' ');
        }
        abc = abc + 1;
    }
    my_putchar('7');
    my_putchar('8');
    my_putchar('9');
    return (0);
}
