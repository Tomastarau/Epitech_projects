/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int my_popup(char * affiche);


#define ERROR 84
#define OK 1

int is_there_some_errors(int argc, char *argv[]){
    char tma[] ="ERROR : Too much arguments\nPlease use ./my_popup [str]\n";
    if (argc > 2){
        write(2, tma, sizeof(tma) / sizeof(char));
        return (ERROR);
    }
    if (argc < 2){
        write(2, "ERROR : Too less arguments\nPlease use ./my_popup \
[str]\n", 56);
        return (ERROR);
    }
    return OK;
}

int main(int argc, char * argv[])
{
    if  (is_there_some_errors(argc, argv) == ERROR) {
        return ERROR;
    } else {
        my_popup(argv[1]);
        return 0;
    }
}
