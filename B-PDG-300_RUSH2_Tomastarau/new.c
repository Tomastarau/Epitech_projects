/*
** EPITECH PROJECT, 2024
** Project_Epitech
** File description:
** new
*/

#include <stdlib.h>

#include "new.h"
#include "player.h"
#include "point.h"
#include "player.h"
#include "vertex.h"
#include "array.h"


Object *new(const Class *class, ...)
{
    Object *obj;
    va_list args;

    if (!class)
        raise("Invalid class");
    va_start(args, class);
    obj = va_new(class, &args);
    va_end(args);
    return obj;
}

Object *va_new(const Class *class, va_list *ap) {
    Object *obj;

    if (!class) {
        raise("Invalid class");
    }
    obj = malloc(class->__size__);
    if (!obj) {
        raise("Memory allocation failed");
    }
    memcpy(obj, class, class->__size__);
    if (class->__ctor__) {
        class->__ctor__(obj, ap);
    }
    return obj;
}

void delete(Object *ptr)
{
    if (!ptr)
        return;
    ((Class *)ptr)->__dtor__(ptr);
}
