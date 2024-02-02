/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Exercise 04 - Float
*/

#include <stdio.h>
#include <stdarg.h>
#include "struct.h"
#include "float.h"
#include "new.h"

static FloatClass *float_add(FloatClass *ptr_one, FloatClass *ptr_two)
{
    float value = ptr_one->value + ptr_two->value;

    return (FloatClass *)new(Float, value);
}

static FloatClass *float_subtract(FloatClass *ptr_one, FloatClass *ptr_two)
{
    float value = ptr_one->value - ptr_two->value;

    return (FloatClass *)new(Float, value);
}

static FloatClass *float_multiply(FloatClass *ptr_one, FloatClass *ptr_two)
{
    float value = ptr_one->value * ptr_two->value;

    return (FloatClass *)new(Float, value);
}

static FloatClass *float_divide(FloatClass *ptr_one, FloatClass *ptr_two)
{
    float value;

    if (ptr_two->value == 0.0f)
        raise("Division by zero");
    value = ptr_one->value / ptr_two->value;
    return (FloatClass *)new(Float, value);
}

static bool float_equal(FloatClass *ptr_one, FloatClass *ptr_two)
{
    return ptr_one->value == ptr_two->value;
}

static bool float_greater_than(FloatClass *ptr_one, FloatClass *ptr_two)
{
    return ptr_one->value > ptr_two->value;
}

static bool float_less_than(FloatClass *ptr_one, FloatClass *ptr_two)
{
    return ptr_one->value < ptr_two->value;
}

static char *float_to_string(FloatClass *this)
{
    int size = snprintf(NULL, 0, "<%s (%f)>",
    this->base.__name__, this->value);
    char *str = malloc(sizeof(char) * (size + 1));

    if (!str)
        raise("Memory allocation failed");
    snprintf(str, size + 1, "<%s (%f)>", this->base.__name__, this->value);
    return str;
}

static void float_ctor(FloatClass *this, va_list *args)
{
    this->value = va_arg(*args, double);
}

static void float_dtor(FloatClass *this)
{
    free(this);
}

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&float_ctor,
        .__dtor__ = (dtor_t)&float_dtor,
        .__str__ = (to_string_t)&float_to_string,
        .__add__ = (binary_operator_t)&float_add,
        .__sub__ = (binary_operator_t)&float_subtract,
        .__mul__ = (binary_operator_t)&float_multiply,
        .__div__ = (binary_operator_t)&float_divide,
        .__eq__ = (binary_comparator_t)&float_equal,
        .__gt__ = (binary_comparator_t)&float_greater_than,
        .__lt__ = (binary_comparator_t)&float_less_than
    },
    .value = 0.0f
};

const Class *Float = (const Class *)&_description;
