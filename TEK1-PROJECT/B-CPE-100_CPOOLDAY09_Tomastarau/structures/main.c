/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <stdio.h>
#include "mya.h"

void change_name(student_t* student, char* name)
{
    student->name = name;
}

student_t change_forname(student_t student, char* forname)
{
    student.forname = forname;
    return student;
}

int get_age()
{
    return 22;
}
      
int main(int ac, char ** av)
{
    student_t paul ={.forname = "Paul", .name = "DUPONT", .age = 18};

    printf("Student : M.%s %s is %d yo\n", paul.name, paul.forname, paul.age);

    change_name(&paul, "DELARUE");

    printf("Student : M.%s %s is %d yo\n", paul.name, paul.forname, paul.age);

    paul = change_forname(paul, "Jean");

    printf("Student : M.%s %s is %d yo\n", paul.name, paul.forname, paul.age);

    paul.age = get_age();

    printf("Student : M.%s %s is %d yo\n", paul.name, paul.forname, paul.age);

    return (0);
}