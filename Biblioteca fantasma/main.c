#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
int main()
{
    //printf("Hello world!\n");
    char sex;
    obtenerSexo(&sex);
    printf("El sexo es: %c\n",sex);
    return 0;
}
