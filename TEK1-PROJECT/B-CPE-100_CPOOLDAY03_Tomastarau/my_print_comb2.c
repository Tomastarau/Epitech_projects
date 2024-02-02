/*
** EPITECH PROJECT, 2022
** my_print_comb2
** File description:
** task06
*/
    
int my_print_comb2(void)
{
    int ab = 00;
    int cd = 01;
    while (ab != 99 ){
        if (cd / 10 % 10 == 9 && cd % 10 == 9){
            ab = ab + 1;
        }
        if (ab / 10 % 10 <= cd / 10 % 10 && ab % 10 < cd % 10){
            my_putchar((ab / 10 % 10) + 48);
            my_putchar((ab % 10) + 48);
            my_putchar(' ');
            my_putchar((cd / 10 % 10) + 48);
            my_putchar((cd % 10) + 48);
            my_putchar(',');
            my_putchar(' ');   
        }
        cd = cd + 1;
    }
    return (0);
}
