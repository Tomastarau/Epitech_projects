/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "cat.h"

int main(int ac, char * av[])
{
    return (cat(av, ac));
}
