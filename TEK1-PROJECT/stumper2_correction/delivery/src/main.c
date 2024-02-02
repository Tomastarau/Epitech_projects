//HEADER

#include "my.h"



int main(int argc, char *argv[])
{
    const char* error = "Usage: ./hidenp needle haystack\n";

    if (argc != 3 ||  my_strlen(argv[1]) < 1 || my_strlen(argv[2]) < 1)
        return puterror(error, RETURN_ERROR);
    return hidenp(argv);
}
