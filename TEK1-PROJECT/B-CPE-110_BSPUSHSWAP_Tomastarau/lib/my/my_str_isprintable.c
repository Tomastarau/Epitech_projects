/*
** EPITECH PROJECT, 2022
** my_str_is_printable
** File description:
** task day06
*/

int my_strlen(char const *str);

void my_putchar(char c);

int my_putstr(char const *str);

int my_str_isprintable(char const *str)
{
    int i = 0;

    if (my_strlen(str) == 0){
        return (1);
    }
    while (str[i] != '\0'){
        if (str[i] >= 32 && str[i] <= 127){
            i = i + 1;
        }else{
            return (0);
        }
    }
    return (1);
}
