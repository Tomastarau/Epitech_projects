/*
** EPITECH PROJECT, 2022
** my_ls_folder
** File description:
** my_ls_folder
*/
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "tree.h"
#include "my.h"

static char *update_path(char* name, char* file)
{
    char *dirp_name = malloc(sizeof(char) * (my_strlen(name) +
        my_strlen(file) + 1));
    my_strcat(dirp_name, file);
    my_strcat(dirp_name, "/");
    my_strcat(dirp_name, name);
    dirp_name[my_strlen(name) + my_strlen(file) + 1] = '\0';
    return dirp_name;
}

static void print_name(struct dirent *dirp, int x, int y)
{
    y == 4 ? write(1, "|-- ", 4) : write(1, "| ", 2);
    write(1, dirp->d_name, my_strlen(dirp->d_name));
    x == 1 ? write(1, "\n", 1) : write(1, "\n    ", 5);
}

int print_file_folder(int argc, char *const file, struct dirent *dirp)
{
    char *path = file;
    char *dirp_name = NULL;
    struct stat stats;
    DIR *dir = opendir (file);
    if (!dir || stat(file, &stats) == 1){
        write(2, "File or directory does not exist\n", 34);
        return (1);}
    while ((dirp = readdir(dir)) != NULL){
        if (dirp->d_type == DT_DIR && my_strncmp(dirp->d_name, ".", 1) != 0
            && my_strncmp(dirp->d_name, "..", 2) != 0) {
            print_name(dirp, 5, 4);
            dirp_name = update_path(dirp->d_name, file);
            print_file_folder(argc, dirp_name, dirp);
        }
        if (dirp->d_name[0] == '.' || (stat(dirp->d_name, &stats) == 0 &&
            (stats.st_mode & S_IFDIR) == 0)) continue;
        if (dirp->d_type != DT_DIR) {
            print_name(dirp, 1, 2);
        }
    } return 0;
}
