#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int suma(int num1, int num2)
{
    int res;
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);
    printf("El primer numero es %d y el segundo es %d\n",num1,num2);
    res = num1 + num2;
    return res;
}
int resta(int num1, int num2)
{
    int res;
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);
    printf("El primer numero es %d y el segundo es %d\n",num1,num2);
    res = num1 - num2;
    return res;
}
int multiplicar(int num1, int num2)
{
    int res;
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);
    printf("El primer numero es %d y el segundo es %d\n",num1,num2);
    res = num1 * num2;
    return res;
}
int dividir(int num1, int num2)
{
    int res;
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);
    while(num2 == 0)
    {
        printf("No se puede dividir por cero, ingrese un valor valido\n");
        printf("Ingrese el primer numero: ");
        scanf("%d", &num1);
        printf("Ingrese el segundo numero: ");
        scanf("%d", &num2);
    }
     printf("El primer numero es %d y el segundo es %d\n",num1,num2);
     res = num1 / num2;


    return res;
}
