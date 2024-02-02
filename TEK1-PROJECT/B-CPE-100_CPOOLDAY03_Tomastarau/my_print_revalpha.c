/*
** EPITECH PROJECT, 2022
** my_print_revalpha
** File description:
** print revalpha
*/

void my_putchar(char c);

int my_print_revalpha(void)
{
    char letter;
    letter = 122;
    while (letter > 96){
        my_putchar (letter);
        letter = letter - 1;
    }
    my_putchar('\n');
    return (0);
}
