#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "calc.h"

int main()
{
    int num1;
	int num2;
	int resultado;

	char salir;
	char opcion;

    do
    {
            system("cls");
            printf("-----Menu de Opciones----- \n\n");
            printf("a- Sumar\n");
            printf("b- Restar\n");
            printf("c- Multiplicar\n");
            printf("d- Dividir\n");
            printf("e- Salir\n\n");
            printf("Indique opcion: ");
            fflush(stdin);
            opcion = getchar();

        switch(opcion)
        {
        case 'a':
            printf("Usted eligio sumar\n");
            resultado = suma(num1,num2);
            printf("El resultado es: %d\n",resultado);
            system("pause");
            break;
        case 'b':
            printf("Usted eligio restar\n");
            resultado = resta(num1,num2);
            printf("El resultado es: %d\n",resultado);
            system("pause");
            break;
        case 'c':
            printf("Usted eligio multiplicar\n");
            resultado = multiplicar(num1,num2);
            printf("El resultado es: %d\n",resultado);
            system("pause");
            break;
        case 'd':
            printf("Usted eligio dividir\n");
            resultado = dividir(num1,num2);
            printf("El resultado es: %d\n",resultado);
            system("pause");
            break;
        case 'e':
            printf("Confirma salida?\n");
            fflush(stdin);
            salir = getchar();
            break;
        default:
            printf("Opcion invalida\n\n");
            system("pause");
            break;
        }
        printf("Confirma salida?\n");
        fflush(stdin);
        salir = getchar();
    }while(salir == 'n');




    return 0;
}
