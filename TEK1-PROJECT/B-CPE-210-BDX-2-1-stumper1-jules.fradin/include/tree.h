//
// EPITECH PROJECT, 2023
// header file
// File description:
// header file
//

#ifndef TREE_
    #define TREE_
    #include <stdbool.h>

typedef struct {
    bool a;
    bool d;
    bool L;
    bool f;
}options;

int print_file_folder(int argc, char *const file, struct dirent *dirp);
int tree(int const argc, char const *const *argv);

#endif
