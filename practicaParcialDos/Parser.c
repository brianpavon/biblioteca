#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Cachorros.h"



int parser_parserCachorros(char* fileName, LinkedList* listaCachorros)
{
	int retorno = -1;
	Cachorro* auxCachorro;

	char id[50];
	char nombre[50];
	char dias[50];
	char raza[50];
	char reservado[50];
	char genero[50];

	FILE* pFile;


	pFile = fopen(fileName,"r");

	if(listaCachorros != NULL && pFile != NULL)
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,dias,raza,reservado,genero);

		do
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,dias,raza,reservado,genero);
			auxCachorro = cachorro_newParametros(id,nombre,dias,raza,reservado,genero);
			if(auxCachorro != NULL)
			{
				ll_add(listaCachorros,auxCachorro);
				retorno = 1;
			}
			else
				break;

		}while(!feof(pFile));
	}
	fclose(pFile);
	fileName = NULL;
    return retorno; // OK
}




/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int saveArchivo(char* path , LinkedList* listaCachorros)
{
    Cachorro* auxCachorro;
    int retorno = -1;
    int i;

    int id;
    char nombre[50];
    int dias;
    char raza[50];
    char reservado[3];
    char genero[2];

    FILE* pFile;
    pFile = fopen(path,"wb");

	if(pFile != NULL)
    {
        fprintf(pFile,"id,nombre,dias,raza,reservado,genero\n");
        for(i=0; i<ll_len(listaCachorros); i++)
        {
            auxCachorro = ll_get(listaCachorros,i);

            cachorro_getId(auxCachorro,&id);
            cachorro_getNombre(auxCachorro,nombre);
            cachorro_getDias(auxCachorro,&dias);
            cachorro_getRaza(auxCachorro,raza);
            cachorro_getReservado(auxCachorro,reservado);
            cachorro_getGenero(auxCachorro,genero);
            fprintf(pFile,"%d,%s,%d,%s,%s,%s\n",id,nombre,dias,raza,reservado,genero);
            retorno = 0;
        }
    }
	fclose(pFile);

    return retorno;
}
