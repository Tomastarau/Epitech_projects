/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Exercise 02
*/

#include <stdio.h>
#include "vertex.h"
#include "struct.h"

static VertexClass *vertex_addition(VertexClass *ptr_one, VertexClass *ptr_two)
{
    int x = ptr_one->x + ptr_two->x;
    int y = ptr_one->y + ptr_two->y;
    int z = ptr_one->z + ptr_two->z;

    Object *this = new(Vertex, x, y, z);
    return this;
}

static VertexClass *vertex_sub(VertexClass *ptr_one, VertexClass *ptr_two)
{
    int x = ptr_one->x - ptr_two->x;
    int y = ptr_one->y - ptr_two->y;
    int z = ptr_one->z - ptr_two->z;

    Object *this = new(Vertex, x, y, z);
    return this;
}

static VertexClass *vertex_multiply(VertexClass *ptr_one, VertexClass *ptr_two)
{
    int x = ptr_one->x * ptr_two->x;
    int y = ptr_one->y * ptr_two->y;
    int z = ptr_one->z * ptr_two->z;

    Object *this = new(Vertex, x, y, z);
    return this;
}

static VertexClass *vertex_divide(VertexClass *ptr_one, VertexClass *ptr_two)
{
    if (ptr_two->x == 0 || ptr_two->y == 0 || ptr_two->z == 0)
        raise("Division by zero");
    int x = ptr_one->x / ptr_two->x;
    int y = ptr_one->y / ptr_two->y;
    int z = ptr_one->z / ptr_two->z;

    Object *this = new(Vertex, x, y, z);
    return this;
}

static bool vertex_equal(VertexClass *ptr_one, VertexClass *ptr_two)
{
    int x = ptr_one->x - ptr_two->x;
    int y = ptr_one->y - ptr_two->y;
    int z = ptr_one->z - ptr_two->z;

    if (x == 0 && y == 0 && z == 0)
        return true;
    return false;
}

static bool vertex_lowerthan(VertexClass *ptr_one, VertexClass *ptr_two)
{
    int x = ptr_one->x - ptr_two->x;
    int y = ptr_one->y - ptr_two->y;
    int z = ptr_one->z - ptr_two->z;

    if (x < 0 && y < 0 && z < 0)
        return true;
    return false;
}

static bool vertex_greaterthan(VertexClass *ptr_one, VertexClass *ptr_two)
{
    int x = ptr_one->x - ptr_two->x;
    int y = ptr_one->y - ptr_two->y;
    int z = ptr_one->z - ptr_two->z;

    if (x > 0 && y > 0 && z > 0)
        return true;
    return false;
}

static char *vertex_to_string(VertexClass *this)
{
    int size = snprintf(NULL, 0, "<%s (%d, %d, %d)>", this->base.__name__,
        this->x, this->y, this->z);

    char *str = malloc(sizeof(char) * (size + 1));
    if (!str)
        raise("Memory allocation failed");
    snprintf(str, size + 1, "<%s (%d, %d, %d)>", this->base.__name__,
        this->x, this->y, this->z);
    return str;
}

static void vertex_creator(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void vertex_destructor(VertexClass *this)
{
    if (this == NULL)
        return;
    free(this);
}

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&vertex_creator,
        .__dtor__ = (dtor_t)&vertex_destructor,
        .__str__ = (to_string_t)&vertex_to_string,
        .__add__ = (binary_operator_t)&vertex_addition,
        .__sub__ = (binary_operator_t)&vertex_sub,
        .__mul__ = (binary_operator_t)&vertex_multiply,
        .__div__ = (binary_operator_t)&vertex_divide,
        .__eq__ = (binary_comparator_t)&vertex_equal,
        .__gt__ = (binary_comparator_t)&vertex_greaterthan,
        .__lt__ = (binary_comparator_t)&vertex_lowerthan
    },
    .x = 0,
    .y = 0,
    .z = 0,
};

const Class *Vertex = (const Class *)&_description;
