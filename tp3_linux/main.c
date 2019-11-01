#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados,
     USANDO LA FUNCION ll_sort(lista,funcionCrit,0)
     COMO QUERAMOS, USAMOS LA FUNCION, HAY QUE PASARLE LA LINKEDLIST Y UNA FUNCION
     ESA FUNCION RECIBE 2 ARGUMENTOS Y DEVUELVE UN NRO
     ESA FUNCION SE LLAMARA CRITERIO
     int funcionCrit(void* arg1,void* arg2) para ordenar por nombre
     {
     	 Employee* pE1 = (Employee*)arg1;
     	 Employee* pE2 = (Employee*)arg2;
     	 emp_getNombre();
     	 return strcmp(pE1->nombre,pE2->nombre);
     }
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).ESCRIBIR CON OTRO NOMBRE
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
    int option;

    LinkedList* pArrayListEmployee = ll_newLinkedList();
    printf(	 "Menu:\n\n"
			 "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
			 "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
			 "3. Alta de empleado\n"
			 "4. Modificar datos de empleado\n"
			 "5. Baja de empleado\n"
			 "6. Listar empleados\n"
			 "7. Ordenar empleados\n"
			 "8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
			 "9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n"
			"10. Salir\n");
    getInt(&option,"Elija una opcion\n","Opcion invalida\n",0,10,2);
    do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",pArrayListEmployee);
                break;
            case 2:

            	break;
            case 3:

            	break;
        }
    }while(option != 10);
    return EXIT_SUCCESS;
}

