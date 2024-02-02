/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Exercice 05
*/

#include "struct.h"

static void array_iterator_creator(array_iterator_class_t *this, va_list *args)
{
    this->_array = va_arg(*args, array_class_t *);
    this->_idx = va_arg(*args, int);
}

static bool array_iterator_eq(array_iterator_class_t *this,
    array_iterator_class_t *other)
{
    return (this->_idx == other->_idx);
}

static bool array_iterator_gt(array_iterator_class_t *this,
    array_iterator_class_t *other)
{
    return (this->_idx > other->_idx);
}

static bool array_iterator_lt(array_iterator_class_t *this,
    array_iterator_class_t *other)
{
    return (this->_idx < other->_idx);
}

static void array_iterator_incr(array_iterator_class_t *this)
{
    this->_idx += 1;
}

static Object *array_iterator_getval(array_iterator_class_t *this)
{
    if (this->_idx >= this->_array->_size)
        raise("Out of range");
    return (this->_array->_tab[this->_idx]);
}

static void array_iterator_setval(array_iterator_class_t *this, ...) {
    va_list args;
    Object *new_obj;

    va_start(args, this);
    new_obj = va_new(this->_array->_type, &args);
    va_end(args);
    if (this->_idx >= this->_array->_size) {
        raise("Out of range");
    }
    delete(this->_array->_tab[this->_idx]);
    this->_array->_tab[this->_idx] = new_obj;
}

static const array_iterator_class_t array_iterator_descr = {
    {   /* Iterator struct */
        {   /* Class struct */
            .__size__ = sizeof(array_iterator_class_t),
            .__name__ = "ArrayIterator",
            .__ctor__ = (ctor_t)&array_iterator_creator,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&array_iterator_eq,
            .__gt__ = (binary_comparator_t)&array_iterator_gt,
            .__lt__ = (binary_comparator_t)&array_iterator_lt,
        },
        .__incr__ = (incr_t)&array_iterator_incr,
        .__getval__ = (getval_t)&array_iterator_getval,
        .__setval__ = (setval_t)&array_iterator_setval,
    },
    ._array = NULL,
    ._idx = 0
};

static const Class *array_iterator = (const Class *)&array_iterator_descr;

static void array_destructor(array_class_t *this)
{
    for (unsigned int i = 0; i < this->_size; i++)
        delete(this->_tab[i]);
    free(this->_tab);
}

static size_t array_len(array_class_t *this)
{
    return (this->_size);
}

static Iterator *array_begin(array_class_t *this)
{
    return (new(array_iterator, this, 0));
}

static Iterator *array_end(array_class_t *this)
{
    return (new(array_iterator, this, this->_size));
}

static Object *array_getitem(array_class_t *this, ...)
{
    size_t index;
    va_list args;

    va_start(args, this);
    index = va_arg(args, size_t);
    va_end(args);
    for (size_t i = 0; i != index; i++) {
        if (this->_tab[i] == NULL) {
            raise("Invalid index");
        }
    }
    return this->_tab[index];
}

static void array_setitem(array_class_t *this, ...) {
    va_list args;
    size_t index;
    Object *new_obj;

    va_start(args, this);
    index = va_arg(args, size_t);
    if (index >= this->_size) {
        va_end(args);
        raise("Invalid index");
    }
    
    Class *cls = va_arg(args, Class *);
    new_obj = va_new(cls, &args);  // Potential issue
    va_end(args);

    if (this->_tab[index] != NULL) {
        delete(this->_tab[index]);
    }
    this->_tab[index] = new_obj;
}



static void array_creator(array_class_t *this, va_list *args) {
    // Set the necessary function pointers for the array
    this->base.__begin__ = (iter_t)&array_begin;
    this->base.__end__ = (iter_t)&array_end;
    this->base.__len__ = (len_t)&array_len;
    this->base.__getitem__ = (getitem_t)&array_getitem;
    this->base.__setitem__ = (setitem_t)&array_setitem;

    // Set the type of elements the array will hold
    this->_type = va_arg(*args, Class*);

    // Allocate memory for the array's elements
    this->_size = va_arg(*args, size_t);
    this->_tab = malloc(this->_size * sizeof(Object*));
    if (!this->_tab)
        raise("Memory allocation failed");

    for (size_t i = 0; i < this->_size; i++) {
        this->_tab[i] = NULL;
    }
}

static const array_class_t _descr = {
    {   /* Container struct */
        {   /* Class struct */
            .__size__ = sizeof(array_class_t),
            .__name__ = "Array",
            .__ctor__ = (ctor_t)&array_creator,
            .__dtor__ = (dtor_t)&array_destructor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&array_len,
        .__begin__ = (iter_t)&array_begin,
        .__end__ = (iter_t)&array_end,
        .__getitem__ = (getitem_t)&array_getitem,
        .__setitem__ = (setitem_t)&array_setitem,
    },
    ._type = NULL,
    ._size = 0,
    ._tab = NULL
};

const Class *Array = (const Class *)&_descr;
