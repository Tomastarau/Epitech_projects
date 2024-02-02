/*
** EPITECH PROJECT, 2022
** rush 1
** File description:
** 1st rush
*/

void my_putchar(char c);

void my_putstr(char const *str);

void line (int x)
{
    int i = 0;

    while (i < x){
        if (i == 0 || i == (x - 1)){
            my_putchar('o');
        }else{
            my_putchar('-');
        }
        i = i + 1;
    }
    my_putchar('\n');
}

void middle_line(int x)
{
    int i = 0;

    while (i < x){
        if (i == 0 || i == (x - 1)){
            my_putchar('|');
        }else{
            my_putchar(' ');
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
    line(x);
    while (middle_i < y - 2){
        middle_line(x);
        middle_i = middle_i + 1;
    }
    if (y != 1){
        line(x);
    }
}
