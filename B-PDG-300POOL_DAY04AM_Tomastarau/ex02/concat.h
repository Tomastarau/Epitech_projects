/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Exercise 02
*/

#ifndef MUL_DIV_H_
    #define MUL_DIV_H_
    #pragma once
typedef struct concat_s {
    const char *str1;
    const char *str2;
    char *res;
} concat_t;
void concat_strings(const char *str1, const char *str2, char **res);
void concat_struct(concat_t *str);
#endif /* !MUL_DIV_H_ */
