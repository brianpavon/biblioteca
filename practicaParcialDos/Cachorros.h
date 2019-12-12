#ifndef CACHORROS_H_
#define CACHORROS_H_

#include "utn.h"
#include "LinkedList.h"
#define HORA_MAXIMA 250
#define SUELDO_MAXIMO 100000
#define ID_MAXIMO 10000
typedef struct
{
    int id;
    char nombre[50];
    int dias;
    char raza[50];
    char reservado[3];
    char genero[2];
}Cachorro;


Cachorro* cachorro_new();
Cachorro* cachorro_newParametros(	char* idStr,
									char* nombreStr,
									char* diasStr,
									char* razaStr,
									char* reservadoStr,
									char* generoStr);

void cachorro_delete(Cachorro* this);

int cachorro_setId(Cachorro* this,int id);
int cachorro_getId(Cachorro* this,int* id);

int cachorro_setNombre(Cachorro* this,char* nombre);
int cachorro_getNombre(Cachorro* this,char* nombre);

int cachorro_setDias(Cachorro* this,int dias);
int cachorro_getDias(Cachorro* this,int* dias);

int cachorro_setRaza(Cachorro* this,char* raza);
int cachorro_getRaza(Cachorro* this,char* raza);

int cachorro_setReservado(Cachorro* this,char* reservado);
int cachorro_getReservado(Cachorro* this,char* reservado);

int cachorro_setGenero(Cachorro* this,char* genero);
int cachorro_getGenero(Cachorro* this,char* genero);

void cachorro_imprimirCachorro(Cachorro* this);
int cachorro_filtrarMenoresDias(void* pElement);
int cachorro_filtrarCallejeros(void* pElement);
int cachorro_filtrarMachos(void* pElement);
//int cachorro_ordenarPorNombre(void* cachorroUno, void* cachorroDos);
//int cachorro_ordenarPorHoras(void* cachorroUno, void* cachorroDos);
//int cachorro_ordenarPorSueldo(void* cachorroUno, void* cachorroDos);
int cachorro_imprimirTodosLosCachorros(LinkedList* pAarrayPuppyList);
int cachorro_buscarPorId(LinkedList* pAarrayPuppyList);
//void cachorro_menuModificacion(LinkedList* pAarrayEmployeeList);
//int cachorro_modificarNombre(Cachorro* this);
//int cachorro_modificarSueldo(Cachorro* this);
//int cachorro_modificarHorasTrabajadas(Cachorro* this);
int cargarListaFiltradaGenero(LinkedList* this);
int imprimirListaFiltradaCallejero(LinkedList* this);
int cargarListaFiltradaMenoresDias(LinkedList* this);

#endif /* CACHORROS_H_ */
