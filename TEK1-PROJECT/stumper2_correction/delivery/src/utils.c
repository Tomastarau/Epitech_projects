//HEADER

#include "my.h"

int my_strlen(const char* str) {
    if (!str)
        return RETURN_FAILURE;
    int len = 0;
    while (str[len])
        len++;
    return len;
}