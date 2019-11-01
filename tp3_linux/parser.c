#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	Employee* auxEmployee;
	char id[4096];
	char nombre[4096];
	char horasTrabajadas[4096];
	char sueldo[4096];
	pFile = fopen("data.csv","r");

		if(!feof(pFile))
		{
			fscanf(pFile,"[^id,nombre,horasTrabajadas,sueldo]\n"
					"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
			auxEmployee = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
			//llamar al new empleados y pasarle todos los parametros
			//auxEmployee = employee_newParametros();
			//verifico lo anterior,
			if(auxEmployee != NULL)
			  {
			  	 ll_add(pArrayListEmployee,auxEmployee);
			  	 retorno = 0;
			  }

		}
		fclose(pFile);

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
