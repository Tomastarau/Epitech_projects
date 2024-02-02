/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** my_ls
*/

#ifndef MY_LS_H_
    #define MY_LS_H_

void my_ls_root(int argc , char const *argv[], DIR *dir);

int my_ls_folder(int argc , char const *argv[], struct dirent *dirp);

void checkoption_l(int argc , char const *argv[], DIR *directory);

void checkoption_a(int argc , char const *argv[], DIR *directory);

int str_in_str(const char *haystack, const char *needle);

void printfileproperties(struct stat stats, struct dirent *dirp);

void printfileproperties_argv(struct stat stats, const char *argv);

void checkrights_user(struct stat stats);

void checkrights_grp(struct stat stats);

void checkrights_other_user_grp_uid(struct stat stats);

void checktype_of_file(struct stat stats);

void check_which_month(struct stat stats);

#endif /* !MY_LS_H_ */
