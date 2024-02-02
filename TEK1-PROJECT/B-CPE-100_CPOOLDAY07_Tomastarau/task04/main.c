/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
int my_putstr(char const *str);

int main(int argc, char **argv)
{
    int i = 0;
    while (argc > i){
        my_putstr(argv[i]);
        i = i + 1;
    }
    return (0);
}
