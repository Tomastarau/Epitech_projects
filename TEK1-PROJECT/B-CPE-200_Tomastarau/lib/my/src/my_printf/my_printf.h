/*
** EPITECH PROJECT, 2022
** my_my_printf.h
** File description:
** .h file for my_printf, struct flags
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_
    #include <stdarg.h>

int my_printf(const char *restrict format, ...);

int printf_c(va_list ap);

int printf_d(va_list ap);

int printf_i(va_list ap);

int printf_o(va_list ap);

int printf_s(va_list ap);

int printf_u(va_list ap);

int printf_x(va_list ap);

int printf_x_up(va_list ap);

int printf_p(va_list ap);

int printf_pourcentage(va_list ap);

int find_next_flag(const char *format, va_list list, int i);

struct flag_s {
    char flag;
    int (*function)(va_list);
};

extern const struct flag_s FLAGS[11];

#endif /* !MY_PRINTF_H_ */
