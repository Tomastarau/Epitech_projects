/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Exercise 04
*/

#include <stdio.h>
#include <stdarg.h>
#include "struct.h"
#include "new.h"
#include "int.h"

static IntClass *int_addition(IntClass *ptr_one, IntClass *ptr_two)
{
    int value = ptr_one->value + ptr_two->value;

    Object *this = new(Int, value);
    return this;
}

static IntClass *int_subtraction(IntClass *ptr_one, IntClass *ptr_two)
{
    int value = ptr_one->value - ptr_two->value;

    Object *this = new(Int, value);
    return this;
}

static IntClass *int_multiply(IntClass *ptr_one, IntClass *ptr_two)
{
    int value = ptr_one->value * ptr_two->value;

    Object *this = new(Int, value);
    return this;
}

static IntClass *int_divide(IntClass *ptr_one, IntClass *ptr_two)
{
    int value;

    Object *this;
    if (ptr_two->value == 0)
        raise("Division by zero");
    value = ptr_one->value / ptr_two->value;
    this = new(Int, value);
    return this;
}

static bool int_equal(IntClass *ptr_one, IntClass *ptr_two)
{
    return ptr_one->value == ptr_two->value;
}

static bool int_greaterthan(IntClass *ptr_one, IntClass *ptr_two)
{
    return ptr_one->value > ptr_two->value;
}

static bool int_lowerthan(IntClass *ptr_one, IntClass *ptr_two)
{
    return ptr_one->value < ptr_two->value;
}

static char *int_to_string(IntClass *this)
{
    int size = snprintf(NULL, 0, "<%s (%d)>", this->base.__name__,
        this->value);

    char *str = malloc(sizeof(char) * (size + 1));
    if (!str)
        raise("Memory allocation failed");
    snprintf(str, size + 1, "<%s (%d)>", this->base.__name__,
        this->value);
    return str;
}

static void int_creator(IntClass *this, va_list *args)
{
    this->value = va_arg(*args, int);
}

static void int_destructor(IntClass *this)
{
    free(this);
}

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&int_creator,
        .__dtor__ = (dtor_t)&int_destructor,
        .__str__ = (to_string_t)&int_to_string,
        .__add__ = (binary_operator_t)&int_addition,
        .__sub__ = (binary_operator_t)&int_subtraction,
        .__mul__ = (binary_operator_t)&int_multiply,
        .__div__ = (binary_operator_t)&int_divide,
        .__eq__ = (binary_comparator_t)&int_equal,
        .__gt__ = (binary_comparator_t)&int_greaterthan,
        .__lt__ = (binary_comparator_t)&int_lowerthan
    },
    .value = 0
};

const Class *Int = (const Class *)&_description;
