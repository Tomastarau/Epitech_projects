/*
** EPITECH PROJECT, 2022
** task01
** File description:
** my_print_alpha
*/
void my_putchar(char c);

int my_print_alpha(void)
{
    char letter;
    letter = 97;
    while (letter < 123){
        my_putchar(letter);
        letter = letter + 1;
    }
    my_putchar('\n');
    return (0);
}
