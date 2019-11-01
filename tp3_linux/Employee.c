#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"


static int employee_isValidNombre(char* nombre);
static int employee_isValidHorasTrabajadas(char* horasTrabajadas);
static int employee_isValidSueldo(char* sueldo);
static int employee_isValidId(char* id);


Employee* employee_new()
{
	return malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadas,char* sueldo)
{
	Employee* retorno = NULL;
	Employee* this;
	this = employee_new();
	if(this != NULL)
	{
		if( employee_setId(this,idStr)==0 &&
			employee_setNombre(this,nombreStr)==0 &&
			employee_setHorasTrabajadas(this,horasTrabajadas)==0 &&
			employee_setSueldo(this,sueldo)==0)
		{
			retorno = this;
		}
		else
		{
			employee_delete(this);
		}
	}
	return retorno;
}

void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int employee_setId(Employee* this,char* id)
{
	int retorno = -1;
	if(this != NULL && employee_isValidId(id))
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int employee_getId(Employee* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		id = this->id;
		retorno = 0;
	}
	return retorno;
}

static int employee_isValidId(char* id)
{
	return 1;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && employee_isValidNombre(nombre))
	{
		strcpy(this->nombre,nombre);
		retorno = 0;
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 0;
	}

	return retorno;
}

static int employee_isValidNombre(char* nombre)
{
	return 1;
}

int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && employee_isValidHorasTrabajadas(horasTrabajadas))
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,char* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

static int employee_isValidHorasTrabajadas(char* horasTrabajadas)
{
	return 1;
}

int employee_setSueldo(Employee* this,char* sueldo)
{
	int retorno = -1;
	if(this != NULL && employee_isValidSueldo(sueldo))
	{
		this->sueldo = *sueldo;
		retorno = 0;
	}
	return retorno;
}

int employee_getSueldo(Employee* this,char* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}

static int employee_isValidSueldo(char* sueldo)
{
	return 1;
}


