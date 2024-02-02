/*
** EPITECH PROJECT, 2022
** rush 1
** File description:
** 1st rush
*/

void my_putchar(char c);

void my_putstr(char const *str);

void line (int x, char c1, char c2, char c3)
{
    int i = 0;

    while (i < x){
        if (i == 0){
            my_putchar(c1);
        }
        if (i == (x - 1) && i != 0){
            my_putchar(c3);
        }
        if (i != 0 && i != (x - 1)){
            my_putchar(c2);
        }
        i = i + 1;
    }
    my_putchar('\n');
}

void rush(int x, int y)
{
    int middle_i = 0;

    if (x <= 0 || y <= 0){
        my_putstr("Invalid size");
        return ("Invalid size\n");
    }
    if (y == 1 || x == 1){
        line(x, 'B', 'B', 'B');
    } else {
        line(x, 'A', 'B', 'C');
    }
    while (middle_i < y - 2){
        line(x, 'B', ' ', 'B');
        middle_i = middle_i + 1;
    }
    if (y != 1 && x != 1)
        line(x, 'A', 'B', 'C');
    if (y != 1 && x == 1)
        line(x, 'B', 'B', 'B');
}
