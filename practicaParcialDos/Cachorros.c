#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cachorros.h"
#include "utn.h"
#include "LinkedList.h"
#include "parser.h"

static int cachorro_isValidId(int* id);
static int cachorro_isValidNombre(char* nombre);
static int cachorro_isValidDias(int* dias);
static int cachorro_isValidRaza(char* raza);
static int cachorro_isValidReservado(char* reservado);
static int cachorro_isValidGenero(char* genero);


/**
*\brief Solicita memoria para un bloque de estructura la estructura Employee
*\return Retorna la posicion de memoria a la estructura
*/

Cachorro* cachorro_new()
{
	return malloc(sizeof(Cachorro));
}

/**
*\brief Transforma y establece todos los datos de la estructura con los parametros recibidos
*\param char* idStr id del empleado
*\param char* nombreStr nombre del empleado
*\param char* horasTrabajadasStr cantidad de horas trabajadas del empleado
*\param char* sueldoStr sueldo del empleado
* \return Retorna la posicion de memoria a la estructura
*/
Cachorro* cachorro_newParametros(	char* idStr,
									char* nombreStr,
									char* diasStr,
									char* razaStr,
									char* reservadoStr,
									char* generoStr)
{
	Cachorro* retorno = NULL;
	Cachorro* this;
	this = cachorro_new();
	int id;
	int dias;


	id = atoi(idStr);
	dias = atoi(diasStr);


	if(this != NULL)
	{
		if( cachorro_setId(this,id)==0 &&
			cachorro_setNombre(this,nombreStr)==0 &&
			cachorro_setDias(this,dias)==0 &&
			cachorro_setRaza(this,razaStr)==0 &&
			cachorro_setReservado(this,reservadoStr)==0 &&
			cachorro_setGenero(this,generoStr)==0)
		{
			retorno = this;
		}
		else
		{
			cachorro_delete(this);
		}
	}
	return retorno;
}

/**
*\brief imprime un empleado que se encuentra cargado en la estructura Employee
*\param Employee* this puntero a la estructura Employee
*/
void cachorro_imprimirCachorro(Cachorro* this)
{

	int id;
	char nombre[50];
	int dias;
	char raza[50];
	char reservado[6];
	char genero[2];

    cachorro_getId(this,&id);
    cachorro_getNombre(this,nombre);
    cachorro_getDias(this,&dias);
    cachorro_getRaza(this,raza);
    cachorro_getReservado(this,reservado);
    cachorro_getGenero(this,genero);

    printf("%5d %10s %10d %10s %10s %10s\n",id,nombre,dias,raza,reservado,genero);

}

/**
*\brief libera el espacio de memoria que ocupaba la estructura de Employee
*\param Employee* this puntero a la estructura Employee
*/
void cachorro_delete(Cachorro* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/**
*\brief setea un ID a un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  int id el entero que se establecera como id
*\return retorna 0 si salio OK -1 si fallo
*/

int cachorro_setId(Cachorro* this,int id)
{
	int retorno = -1;
	if(this != NULL && cachorro_isValidId(&id))
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

/**
*\brief obtiene un ID de un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  int id el entero al que se le pasara el id obtenido
*\return retorna 0 si salio OK -1 si fallo
*/
int cachorro_getId(Cachorro* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

/**
*\brief Valida que el entero ingresado como id sea numerico
*\param  int id el entero que se validara
*\return retorna 1 si salio OK -1 si fallo
*/
static int cachorro_isValidId(int* id)
{
     int retorno =-1;
     int i=0;

     if(id != NULL)
     {
        while(id[i] != '\0')
        {
        if(id[i]<'0' || id[i]>'9')
        break;
        i++;
     }
        if(id[i] == '\0')
        retorno = 1;
     }

	return retorno;
}

/**
*\brief carga un nombre a un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  char* nombre es el string de caracteres que se pasara como nombre
*\return retorna 0 si salio OK -1 si fallo
*/

int cachorro_setNombre(Cachorro* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && cachorro_isValidNombre(nombre))
	{
		strcpy(this->nombre,nombre);
		retorno = 0;
	}
	return retorno;
}

/**
*\brief obtiene un nombre de un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  char* nombre es el string de caracteres al que se le pasara el nombre obtenido
*\return retorna 0 si salio OK -1 si fallo
*/
int cachorro_getNombre(Cachorro* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 0;
	}

	return retorno;
}

/**
*\brief valida un nombre de un elemento de la estructura Employee
*\param  char* nombre es el string de caracteres que se le pasara
*\return retorna 1 si salio OK -1 si fallo
*/
static int cachorro_isValidNombre(char* nombre)
{
	return 1;
}


/**
*\brief setea las horas trabajadas a un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  int horasTrabajadas el entero que se establecera como horas trabajadas para ese empleado
*\return retorna 0 si salio OK -1 si fallo
*/
int cachorro_setDias(Cachorro* this,int dias)
{
	int retorno = -1;
	if(this != NULL && cachorro_isValidDias(&dias))
	{
		this->dias = dias;
		retorno = 0;
	}
	return retorno;
}

/**
*\brief obtiene las horas trabajadas de un elemento de la estructura Employee y se las pasa a una variable
*\param Employee* this puntero a la estructura Employee
*\param  int horasTrabajadas el entero al que se le pasaras las horas trabajadas de ese empleado
*\return retorna 0 si salio OK -1 si fallo
*/
int cachorro_getDias(Cachorro* this,int* dias)
{
	int retorno = -1;
	if(this != NULL && dias != NULL)
	{
		*dias = this->dias;
		retorno = 0;
	}
	return retorno;
}

/**
*\brief valida que las horas trabajadas sean numeros validos
*\param  int horasTrabajadas el entero que se validara
*\return retorna 1 si salio OK -1 si fallo
*/
static int cachorro_isValidDias(int* dias)
{
	int retorno =-1;
    int i=0;

     if(dias != NULL)
     {
        while(dias[i] != '\0')
        {
        if(dias[i]<'0' || dias[i]>'9')
        break;
        i++;
     }
        if(dias[i] == '\0')
        retorno = 1;
     }

	return retorno;
}

/**
*\brief carga un sueldo a un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  int sueldo es el sueldo que se cargara al elemento de la estructura
*\return retorna 0 si salio OK -1 si fallo
*/
int cachorro_setRaza(Cachorro* this,char* raza)
{
	int retorno = -1;
	if(this != NULL && cachorro_isValidRaza(raza))
	{
		strcpy(this->raza,raza);
		retorno = 0;
	}
	return retorno;
}


/**
*\brief obtine un sueldo de un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  int sueldo es el sueldo al que se le cargara el sueldo del elemento de la estructura
*\return retorna 0 si salio OK -1 si fallo
*/
int cachorro_getRaza(Cachorro* this,char* raza)
{
	int retorno = -1;
	if(this != NULL && raza != NULL)
	{
		strcpy(raza,this->raza);

		retorno = 0;
	}

	return retorno;
}

/**
*\brief valida que el sueldo sea un entero valido
*\param  int sueldo es el sueldo es el elemento que se validara
*\return retorna 1 si salio OK -1 si fallo
*/
static int cachorro_isValidRaza(char* raza)
{
	return 1;
}

/**
*\brief carga un sueldo a un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  int sueldo es el sueldo que se cargara al elemento de la estructura
*\return retorna 0 si salio OK -1 si fallo
*/
int cachorro_setReservado(Cachorro* this,char* reservado)
{
	int retorno = -1;
	if(this != NULL && cachorro_isValidReservado(reservado))
	{
		strcpy(this->reservado,reservado);
		retorno = 0;
	}
	return retorno;
}


/**
*\brief obtine un sueldo de un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  int sueldo es el sueldo al que se le cargara el sueldo del elemento de la estructura
*\return retorna 0 si salio OK -1 si fallo
*/
int cachorro_getReservado(Cachorro* this,char* reservado)
{
	int retorno = -1;
	if(this != NULL && reservado != NULL)
	{
		strcpy(reservado,this->reservado);
		retorno = 0;
	}

	return retorno;
}

/**
*\brief valida que el sueldo sea un entero valido
*\param  int sueldo es el sueldo es el elemento que se validara
*\return retorna 1 si salio OK -1 si fallo
*/
static int cachorro_isValidReservado(char* reservado)
{
	return 1;
}

/**
*\brief carga un sueldo a un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  int sueldo es el sueldo que se cargara al elemento de la estructura
*\return retorna 0 si salio OK -1 si fallo
*/
int cachorro_setGenero(Cachorro* this,char* genero)
{
	int retorno = -1;
	if(this != NULL && cachorro_isValidGenero(genero))
	{
		strcpy(this->genero,genero);
		retorno = 0;
	}
	return retorno;
}


/**
*\brief obtine un sueldo de un elemento de la estructura Employee
*\param Employee* this puntero a la estructura Employee
*\param  int sueldo es el sueldo al que se le cargara el sueldo del elemento de la estructura
*\return retorna 0 si salio OK -1 si fallo
*/
int cachorro_getGenero(Cachorro* this,char* genero)
{
	int retorno = -1;
	if(this != NULL && genero != NULL)
	{
		strcpy(genero,this->genero);
		retorno = 0;
	}

	return retorno;
}

/**
*\brief valida que el sueldo sea un entero valido
*\param  int sueldo es el sueldo es el elemento que se validara
*\return retorna 1 si salio OK -1 si fallo
*/
static int cachorro_isValidGenero(char* genero)
{
	return 1;
}





/**
*\brief busca un empleado por ID y devuelve su posicion
*\param void* puntero a la estructura Employee
*\param return la posicion del empleado si salio ok, -1 si fallo
*/
int cachorro_buscarPorId(LinkedList* pAarrayPuppyList)
{
    int retorno = -1;
    int id;
    int i;
    Cachorro* auxCachorro;

    cachorro_imprimirTodosLosCachorros(pAarrayPuppyList);
    getInt(&id,"Indique el ID que desea buscar\n","ID INVALIDO",0,ID_MAXIMO,2);

    for(i=0; i<ll_len(pAarrayPuppyList); i++)
    {
        auxCachorro = ll_get(pAarrayPuppyList,i);
        if(auxCachorro->id == id)
        {
            retorno = i;
        }
    }

    return retorno;
}

/**
*\brief imprime todos los elementos cargados en la lista de la estructura Employee
*\param void* puntero a la estructura Employee
*\param return 0 si salio ok, -1 si fallo
*/
int cachorro_imprimirTodosLosCachorros(LinkedList* pAarrayPuppyList)
{
    int retorno = -1;
    int i;
    Cachorro* this;

    if(pAarrayPuppyList != NULL)
    {
        printf("%5s %10s %10s %10s %10s %10s\n","ID","NOMBRE","DIAS","RAZA","RESERVADO","GENERO");
        for(i=0 ; i<ll_len(pAarrayPuppyList); i++)
        {
            /*if(i%150 == 0 && i != 0)
            {
                system("pause");
            }*/
          this = ll_get(pAarrayPuppyList,i);
          cachorro_imprimirCachorro(this);
          retorno = 0;
        }
    }
    return retorno;
}


int cachorro_filtrarMenoresDias(void* pElement)
{
	int retorno = -1;

	Cachorro* auxCachorro;
	auxCachorro = (Cachorro*)pElement;

	if(auxCachorro->dias > 45)
	{
		retorno = 1;
	}
	else
	{
		retorno = 0;
	}


	return retorno;
}


int cachorro_filtrarMachos(void* pElement)
{
	int retorno = -1;

	Cachorro* auxCachorro;
    char genero;

	if(pElement != NULL)
    {
        auxCachorro = (Cachorro*) pElement;

        cachorro_getGenero(auxCachorro,&genero);
        if(genero == 'H')
        {

            retorno = 1;
        }
            else
            {
                retorno = 0;
            }
    }

	return retorno;
}


int cachorro_filtrarCallejeros(void* pElement)
{
	int retorno = -1;
    Cachorro* auxCachorro;

    if(pElement != NULL)
    {
        auxCachorro = (Cachorro*)pElement;

        if(strcmp(auxCachorro->raza,"Callejero")==0)
        {
            retorno = 1;
        }
        else
        {
          retorno = 0;
        }
    }
	return retorno;
}

int cargarListaFiltradaGenero(LinkedList* this)
{
    int retorno = -1;
    LinkedList* listaMachos;
    //Cachorro* auxCachorro;
    //int i;
    if(this != NULL)
    {
       listaMachos = ll_filter(this,cachorro_filtrarMachos);
       if(listaMachos != NULL)
       {
           saveArchivo("Solo machos",listaMachos);
           /*for(i=0; i<ll_len(listaMachos); i++)
           {
               auxCachorro = ll_get(listaMachos,i);
               cachorro_imprimirCachorro(auxCachorro);
               retorno = 0;
           }*/
       }
    }
    return retorno;
}

int imprimirListaFiltradaCallejero(LinkedList* this)
{
    int retorno = -1;
    LinkedList* listaCallejero;
    Cachorro* auxCachorro;
    int i;
    if(this != NULL)
    {
       listaCallejero = ll_filter(this,cachorro_filtrarCallejeros);
       if(listaCallejero != NULL)
       {
           printf("%5s %10s %10s %10s %10s %10s\n","ID","NOMBRE","DIAS","RAZA","RESERVADO","GENERO");
           for(i=0; i<ll_len(listaCallejero); i++)
           {
               auxCachorro = ll_get(listaCallejero,i);
               cachorro_imprimirCachorro(auxCachorro);
               retorno = 0;
           }
       }
    }
    return retorno;
}

int cargarListaFiltradaMenoresDias(LinkedList* this)
{
    int retorno = -1;
    LinkedList* listaMenoresDias;
    //Cachorro* auxCachorro;
    //int i;
    if(this != NULL)
    {
       listaMenoresDias = ll_filter(this,cachorro_filtrarMenoresDias);
       if(listaMenoresDias != NULL)
       {
           saveArchivo("Menores dias",listaMenoresDias);
           /*for(i=0; i<ll_len(listaMenoresDias); i++)
           {
               auxCachorro = ll_get(listaMenoresDias,i);
               cachorro_imprimirCachorro(auxCachorro);
               retorno = 0;
           }*/
       }
    }
    return retorno;
}


