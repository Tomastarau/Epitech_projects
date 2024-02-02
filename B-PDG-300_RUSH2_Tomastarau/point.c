/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Exercise 02
*/

#include <stdio.h>
#include <stdarg.h>
#include "point.h"
#include "struct.h"

static PointClass *point_add(PointClass *ptr_one, PointClass *ptr_two)
{
    int x = ptr_one->x + ptr_two->x;
    int y = ptr_one->y + ptr_two->y;

    Object *this = new(Point, x, y);
    return this;
}

static PointClass *point_sub(PointClass *ptr_one, PointClass *ptr_two)
{
    int x = ptr_one->x - ptr_two->x;
    int y = ptr_one->y - ptr_two->y;

    Object *this = new(Point, x, y);
    return this;
}

static PointClass *point_multiply(PointClass *ptr_one, PointClass *ptr_two)
{
    int x = ptr_one->x * ptr_two->x;
    int y = ptr_one->y * ptr_two->y;

    Object *this = new(Point, x, y);
    return this;
}

static PointClass *point_divide(PointClass *ptr_one, PointClass *ptr_two)
{
    if (ptr_two->x == 0 || ptr_two->y == 0)
        raise("Division by zero");
    int x = ptr_one->x / ptr_two->x;
    int y = ptr_one->y / ptr_two->y;

    Object *this = new(Point, x, y);
    return this;
}

static bool point_equal(PointClass *ptr_one, PointClass *ptr_two)
{
    int x = ptr_one->x - ptr_two->x;
    int y = ptr_one->y - ptr_two->y;

    if (x == 0 && y == 0)
        return true;
    return false;
}

static bool point_lowerthan(PointClass *ptr_one, PointClass *ptr_two)
{
    int x = ptr_one->x - ptr_two->x;
    int y = ptr_one->y - ptr_two->y;

    if (x < 0 && y < 0)
        return true;
    return false;
}

static bool point_greaterthan(PointClass *ptr_one, PointClass *ptr_two)
{
    int x = ptr_one->x - ptr_two->x;
    int y = ptr_one->y - ptr_two->y;

    if (x > 0 && y > 0)
        return true;
    return false;
}

static char *point_to_string(PointClass *this)
{
    int size = snprintf(NULL, 0, "<%s (%d, %d)>", this->base.__name__,
        this->x, this->y);

    char *str = malloc(sizeof(char) * (size + 1));
    if (!str)
        raise("Memory allocation failed");
    snprintf(str, size + 1, "<%s (%d, %d)>", this->base.__name__,
        this->x, this->y);
    return str;
}

static void point_creator(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void point_destructor(PointClass *this)
{
    free(this);
}

// Create additional functions here


static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&point_creator,
        .__dtor__ = (dtor_t)&point_destructor,
        .__str__ = (to_string_t)&point_to_string,
        .__add__ = (binary_operator_t)&point_add,
        .__sub__ = (binary_operator_t)&point_sub,
        .__mul__ = (binary_operator_t)&point_multiply,
        .__div__ = (binary_operator_t)&point_divide,
        .__eq__ = (binary_comparator_t)&point_equal,
        .__gt__ = (binary_comparator_t)&point_greaterthan,
        .__lt__ = (binary_comparator_t)&point_lowerthan
    },
    .x = 0,
    .y = 0,
};

const Class *Point = (const Class *)&_description;
