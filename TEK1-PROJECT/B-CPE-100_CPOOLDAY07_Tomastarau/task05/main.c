/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
int my_putstr(char const *str);

int main(int argc, char **argv)
{
    int i = argc - 1;
    while (i >= 0){
        my_putstr(argv[i]);
        i = i - 1;
    }
    return (0);
}
