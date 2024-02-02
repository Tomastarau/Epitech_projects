/*
** EPITECH PROJECT, 2024
** Project_Epitech
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    #include "object.h"
    #include <stdlib.h>
    #include <stdarg.h>
    #include "raise.h"
    #include "array.h"
    #include "new.h"

typedef struct {
    Class base;
    char *identifier;
    int power;
} PlayerClass;

typedef struct {
    Class base;
    int x;
    int y;
} PointClass;

typedef struct {
    Class base;
    float value;
} FloatClass;

typedef struct {
    Class base;
    int value;
} IntClass;

typedef struct {
    Class base;
    int letter;
} CharClass;

typedef struct {
    Class base;
    int x;
    int y;
    int z;
} VertexClass;

typedef struct array_class_s {
    Container base;
    Class *_type;
    size_t _size;
    Object **_tab;
} array_class_t;

typedef struct array_iterator_class_s {
    Iterator base;
    array_class_t *_array;
    size_t _idx;
} array_iterator_class_t;

#endif /* !STRUCT_H_ */
