/*
** EPITECH PROJECT, 2022
** cat
** File description:
** cat
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int cat(char * const * files, int arg_nbr){
    int fd = 0;
    char buffer[100] = {0};
    int size = 0;
    int i = 1;
    
    while (i < arg_nbr){
        my_putstr(files[i]);
        fd = open(files[i], O_RDONLY, S_IRWXO);
        if (fd == -1){
            write(2, "Error with open", 16);
            return (84);
        }
        while ((size = read(fd, buffer, 100)) > 0){
            write(1, buffer, size);
        }
        close (fd);
        i = i + 1;
    }
    return (0);
}
