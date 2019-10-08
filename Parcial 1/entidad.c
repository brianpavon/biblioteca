#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utn.h"
#include "entidad.h"

#define STATUS_VACIO 0
#define STATUS_OCUPADO 1
#define CANTIDAD_EMPLEADOS 1000
#define CANTIDAD_SECTORES 3

 /**
 * \brief inicializa el estado de un array de estructuras, dejando el estado vacio o en cero
 * \param array a inicializar
 * \param tamanio del array
 * \return Si se pudo realizar devuelve un 0, como señal de OK, sino devuelve -1
 *
 */
int initArrayStruct(sGhost *ghost,int sizeGhost)
{
    int i;//variable de control
	int retorno = -1;
	if(ghost != NULL && sizeGhost > 0)
	{

		for(i=0;i<sizeGhost;i++)
		{
			ghost[i].status = STATUS_VACIO;

		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief busca en un array de estructuras, el primer lugar disponible
 * \param array de estructura
 * \param tamanio del array
 * \return si encontro un lugar devuelve un 0, como señal de OK, sino devuelve -1
 *
 */

int buscarLugarLibre(sGhost *ghost,int sizeGhost)
{
    int index = -1;
	int i;
	if(ghost != NULL && sizeGhost > 0)
	{

		for(i=0;i<sizeGhost;i++)
		{
			if(ghost[i].status == STATUS_VACIO)
			{
				index = i;
				break;
			}
		}

	}
	return index;

}

 /**
 * \brief permite harcodear una estructura de array, cargando datos por defecto
 * \param array de estructura
 * \param tamanio del array
 * \return void
 *
 */

void employees_hcData(sGhost *ghost, int sizeGhost)
{
    int i; //variable de control para los ghosts
    int id[]= {1,8,9,7,2,4};
    char name[][50]= {"Lorena","Eduardo","Carlos","Pedro","Carlos","Mateo"};
    char lastName[][50]={"B","A","B","A","B","A"};
    float salario[]= {22000,22000,15000,4000,21000,6000};
    int sector[]={1,1,3,3,2,2};

    for(i=0; i<sizeGhost; i++)
    {
        ghost[i].id = id[i];
        strcpy(ghost[i].name, name[i]);
        strcpy(ghost[i].lastName, lastName[i]);
        ghost[i].salario = salario[i];
        ghost[i].status = STATUS_OCUPADO;
        ghost[i].sector = sector[i];
    }
}
 /**
 * \brief funcion que nos permitira cargar una estructura en un array
 * \param array de estructura
 * \param tamanio del array de estructura
 * \param array de esturctura con relacion uno a muchos
 * \param tamanio del array de relacion uno a mucho
 * \return si encontro un lugar devuelve un 0, como señal de OK, sino devuelve -1
 *
 */

int addEmployees(sGhost *ghost,int sizeGhost,sGhostDos *ghostDos,int sizeGhostDos,int id)
{
    int i;
    int retorno = -1;
    char respuesta;
    sGhost auxGhost;
    sGhostDos auxGhostDos;
    i=buscarLugarLibre(ghost,sizeGhost);

    if(i!=-1)
    {
            auxGhost.id = id+1;
            getString(auxGhost.name,"Ingrese el nombre del ghost:\n","DATO INCORRECTO\n",0,60,2);
            getString(auxGhost.lastName,"Ingrese el apellido del ghost:\n","DATO INCORRECTO\n",0,60,2);
            auxGhostDos = obtenerGhostDos(ghostDos,sizeGhostDos,ghost);
            auxGhost.sector = auxGhostDos.id;
            getFloat(&auxGhost.salario,"Ingrese el salario del ghost: \n","VALOR INCORRECTO\n",0,200000,2);

            printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
            printf("\n\n%3s %20s %20s %20s %20s\n\n","ID","ghostDos","Nombre","Apellido","Salario");
            mostrarUnGhost(auxGhost,ghostDos,sizeGhostDos);
            printf("\n\n------------------------------------------------------------\n\n");
            getChar(&respuesta,"Confirma el nuevo ghost?Ingrese s para confirmar o n para cancelar\n","El ghost no fue dado de alta\n",'s','z',1);
                if(respuesta == 's')
                {
                    retorno = 0;
                    ghost[i].id = auxGhost.id;
                    strncpy(ghost[i].name,auxGhost.name,51);
                    strncpy(ghost[i].lastName,auxGhost.lastName,51);
                    ghost[i].sector = auxGhostDos.id;
                    ghost[i].salario = auxGhost.salario;
                    ghost[i].status = STATUS_OCUPADO;
                }

        else
        {
            printf("No hay lugar disponible\n");
        }



    }
    return retorno;

}

 /**
 * \brief permite elegir una estructura a relacionar con una principal
 * \param array de estructura con relacion uno a mucho
 * \param tamanio del array de estructura
 * \param array de estructura principal
 * \return devuelve el parametro elegido para relacionar
 *
 */

sGhostDos obtenerGhostDos(sGhostDos *ghostDos, int sizeGhostDos, sGhost *ghost)
{
    int i;
    int auxiliarGhostDos;
    sGhostDos ghostDosRetorno;
    ghostDosRetorno.id = -1;

    do
    {
        for (i=0; i<sizeGhostDos; i++)
        {
            printf("ID %d: %s\n", ghostDos[i].id, ghostDos[i].descripcion);
        }

        getInt(&auxiliarGhostDos,"El ... que corresponde al ID: \n","ERROR",0,CANTIDAD_SECTORES,2);

        for (i=0; i<sizeGhostDos; i++)
        {
            if (ghostDos[i].id==auxiliarGhostDos)
            {
                ghostDosRetorno = ghostDos[i];
            }
        }

        if (ghostDosRetorno.id==-1)
        {
            printf("\nEl .... no existe\n\n");
        }
    }

    while(ghostDosRetorno.id==-1);
    return ghostDosRetorno;
}
 /**
 * \brief funcion que nos muestra todos los campos cargados en la estructura dentro del array
 * \param array de estructura
 * \param tamanio del array de estructura
 * \param array de esturctura con relacion uno a muchos
 * \param tamanio del array de relacion uno a muchos
 * \return si pudo encontrar los campos cargados devuelve un 0, como señal de OK, sino devuelve -1
 *
 */
int imprimirTodosLosGhosts(sGhost *ghost, int sizeGhost,sGhostDos *ghostDos,int sizeGhostDos)
{
	int i; //variable de control para recorrer el array de ghostDos
	int j; //variable de control para recorrer el array de ghosts
    int retorno = -1;
	if(ghost != NULL && sizeGhost>0)
	{
		for(i=0; i<sizeGhostDos; i++)
		{
		    printf("**-------------------------------------------------------------------------**\n\n");
		    printf("%s\n",ghostDos[i].descripcion);
		    printf("\n\n%3s %20s %20s %20s %20s\n\n","ID","ghostDos","Nombre","Apellido","Salario");
		    for(j=0; j<sizeGhost; j++)
            {
                if(ghost[j].status == STATUS_OCUPADO)
                {
                    retorno = 0;
                    if(ghost[j].sector == ghostDos[i].id)
                    mostrarUnGhost(ghost[j],ghostDos,sizeGhostDos);
                }

            }
		}
		printf("**-------------------------------------------------------------------------**\n\n");
	}
    return retorno;
}

 /**
 * \brief funcion que imprimira por pantalla un ghost de acuerdo al id y lo relacionara con su ghostDos
 * \param array de estructura principal
 * \param array de esturctura con relacion uno a muchos
 * \param tamanio del array de relacion uno a mucho
 * \return si pudo encontrar los campos cargados y realizar la relacion devuelve un 0, como señal de OK, sino devuelve -1
 *
 */
int mostrarUnGhost(sGhost unGhost,sGhostDos *ghostDos, int sizeGhostDos)
{
    char descripcionGhostDos[51];
    int i;
    int retorno = -1;
    for(i=0; i<sizeGhostDos; i++)
    {
        if(unGhost.sector==ghostDos[i].id)
        {
            retorno=0;
            strncpy(descripcionGhostDos, ghostDos[i].descripcion,51);
            break;
        }
    }
    printf("%3d %20s %20s %20s %20.2f\n", unGhost.id, descripcionGhostDos, unGhost.name, unGhost.lastName, unGhost.salario);

	return retorno;

}

 /**
 * \brief funcion que va a recorrer el array de estructura, y buscara un elemento por su ID
 * \param array de estructura principal
 * \param tamanio de la estructura principal
 * \param array de esturctura con relacion uno a muchos
 * \param tamanio del array de relacion uno a mucho
 * \return devuelve la posicion del elemento, sino devuelve -1
 *
 */
int buscarGhostPorId(sGhost *ghost, int sizeGhost, sGhostDos *ghostDos, int sizeGhostDos)
{
	int retorno = -1;
	int i;
	int id;
	if(ghost != NULL && sizeGhost >0)
	{
        imprimirTodosLosGhosts(ghost,sizeGhost,ghostDos,sizeGhostDos);
        getInt(&id,"Ingrese el ID que desea buscar\n","El ID no existe\n",0,1000,1);

		for(i=0;i<sizeGhost;i++)
		{
			if(ghost[i].status == STATUS_OCUPADO)
			{
				if(ghost[i].id == id)
				{
					retorno = i; //devuelvo la posicion
					break;
				}

			}

		}
	}
	return retorno;
}

 /**
 * \brief permite al usuario ingresar a un menu de modificaciones
 * \param array de estructura principal
 * \param tamanio de la estructura principal
 * \param array de esturctura con relacion uno a muchos
 * \param tamanio del array de relacion uno a mucho
 * \return void
 *
 */
void menuModificacionGhosts(sGhost *ghost, int sizeGhost, sGhostDos *ghostDos, int sizeGhostDos)
{
    int opcion;
    int i;
    char rta;
    sGhost auxGhost;
    sGhostDos auxGhostDos;

    i = buscarGhostPorId(ghost, sizeGhost, ghostDos, sizeGhostDos);
    if(i != -1)
    {
        do
        {
            system("pause");
            system("cls");
            printf("\n\n\n******---MENU DE MODIFICACION DE ghostS******---\n\n\n");
            imprimirTodosLosGhosts(ghost, sizeGhost, ghostDos, sizeGhostDos);
            printf("1-Modificar el nombre\n2-Modificar el apellido\n3-Modificar el ghostDos\n4-Modificar el salario\n5-Volver al menu anterior\n");
            getInt(&opcion,"Ingrese el dato a modificar\n","No es una opción válida",1,5,2);
            switch(opcion)
            {
                case 1:
                    system("cls");
                    getString(auxGhost.name,"Ingrese el nuevo nombre del ghost:\n","DATO INCORRECTO\n",0,60,2);
                    getChar(&rta,"El nombre se modificara. Ingrese s para continuar...\n","El nombre no se modifica",'s','z',2);
                    if(rta == 's')
                    {
                        strncpy(ghost[i].name,auxGhost.name,51);
                    }
                    break;
                case 2:
                    system("cls");
                    getString(auxGhost.lastName,"Ingrese el nuevo apellido del ghost:\n","DATO INCORRECTO\n",0,60,2);
                    getChar(&rta,"El apellido se modificara. Ingrese s para continuar...\n","El apellido no se modifica",'s','z',2);
                    if(rta == 's')
                    {
                        strncpy(ghost[i].lastName,auxGhost.lastName,51);
                    }
                    break;
                case 3:
                    system("cls");
                    auxGhostDos = obtenerGhostDos(ghostDos,sizeGhostDos,ghost);
                    auxGhost.sector = auxGhostDos.id;
                    getChar(&rta,"El ghostDos se modificara. Ingrese s para continuar...\n","El ghostDos no se modifica",'s','z',2);
                    if(rta == 's')
                    {
                        ghost[i].sector = auxGhostDos.id;
                    }
                    break;
                case 4:
                    system("cls");
                    getFloat(&auxGhost.salario,"Ingrese el nuevo salario del ghost: \n","VALOR INCORRECTO\n",0,200000,2);
                    getChar(&rta,"El salario se modificara. Ingrese s para continuar...\n","El salario no se modifica",'s','z',2);
                    if(rta == 's')
                    {
                        ghost[i].salario = auxGhost.salario;
                    }
                    break;
            }

        }while(opcion != 5);
    }
}

 /**
 * \brief permite al usuario realizar una baja logica de un elemento,colocando el status en vacio de la estructura dentro del array
 * \param array de estructura principal
 * \param tamanio de la estructura principal
 * \param array de esturctura con relacion uno a muchos
 * \param tamanio del array de relacion uno a mucho
 * \return si pudo realizar la baja devuelve un 0, como señal de OK, sino un -1
 *
 */
int bajaGhostPorId(sGhost *ghost, int sizeGhost, sGhostDos *ghostDos, int sizeGhostDos)
{
    int retorno = -1;
    int i;
    char rta;

    system("cls");
    printf("Utilice el ID para dar la baja de ghost\n\n");
    i = buscarGhostPorId(ghost, sizeGhost, ghostDos, sizeGhostDos);
    if(ghost[i].status == STATUS_OCUPADO && i != -1)
    {
        getChar(&rta,"Esta seguro que desea borrar el ghost? Ingrese s para continuar o n para cancelar\n","No se dio de baja\n",'s','z',2);
        if(rta == 's')
        {
            ghost[i].status = STATUS_VACIO;
            printf("El ghost %s %s fue dado de baja\n",ghost[i].name,ghost[i].lastName);
        }

    }
    else
        {
            printf("El ID no corresponde a un ghost activo\n");
        }


    return retorno;
}

 /**
 * \brief ordena los elementos dentro del array de estructura
 * \param array de estructura
 * \param tamanio de la estructura
 * \return si pudo ordenar todos los elementos devuelve un 0, como señal de OK, sino un -1
 *
 */
int ordenarGhosts(sGhost *ghost,int sizeGhost)
{
	int i;
	int retorno = -1;
	sGhost auxGhost;
	int fSwap;
	if(ghost != NULL && sizeGhost>0)
	{
		retorno = 0;
		do
		{
			fSwap = 0;
			for(i=0;i<sizeGhost-1;i++)
			{
				if(strncmp(ghost[i].name,ghost[i+1].name,51)>0)
				{
					fSwap = 1;
					auxGhost = ghost[i];
					ghost[i]= ghost[i+1];
					ghost[i+1]= auxGhost;
				}

			}
		}while(fSwap);
	}
	return retorno;
}

 /**
 * \brief calcula el total de los valores float de un array de estructuras y lo muestra
 * \param array de estructura
 * \param tamanio de la estructura
 * \return muestra el total de la suma de los valores float del array de estructuras
 *
 */
float totalSalariosGhosts(sGhost *ghost, int sizeGhost)
{
    int i;
    float totalSalarios = 0;
    for(i=0 ; i<sizeGhost ; i++)
    {
        if(ghost[i].status == STATUS_OCUPADO)
        {
            totalSalarios+=ghost[i].salario;
        }
    }
    printf("La suma total de los salarios es: %.2f\n",totalSalarios);
    return totalSalarios;
}
 /**
 * \brief calcula el total de los valores float de un array de estructuras y lo muestra
 * \param array de estructura
 * \param tamanio de la estructura
 * \return muestra el promedio de los valores float de los campos float del array de estructura
 *
 */
 void salarioPromedioGhosts(sGhost *ghost,int sizeGhost)
 {
   float salarioTotal;
   float salarioPromedio;
   int i;
   salarioTotal = totalSalariosGhosts(ghost,sizeGhost);
   salarioPromedio = salarioTotal / sizeGhost;

   printf("\n\nEl salario promedio es %.2f: \n\n",salarioPromedio);
   printf("Los ghosts con el salario mas alto al promedio son: \n\n");
   for(i=0 ; i<sizeGhost; i++)
   {
       if(ghost[i].salario>salarioPromedio && ghost[i].status == STATUS_OCUPADO)
       {
           printf("%s %s\n\n",ghost[i].name,ghost[i].lastName);
       }
   }

 }

  /**
 * \brief permite al usuario ingresar a un menu de modificaciones
 * \param array de estructura principal
 * \param tamanio de la estructura principal
 * \param array de esturctura con relacion uno a muchos
 * \param tamanio del array de relacion uno a mucho
 * \return void
 *
 */
 void menuReportes(sGhost *ghost, int sizeGhost, sGhostDos *ghostDos, int sizeGhostDos)
 {
     int opcion;
     system("pause");
     system("cls");
     do
     {
         printf("*****MENU DE REPORTES*****\n");
         getInt(&opcion,"Ingrese la opcion deseada:\n\n1-Ordenar ghosts\n2-Total y promedio de los salarios y cuantos lo superan\n3-Volver al menu anterior\n","Opcion Invalida",1,4,2);
         switch(opcion)
         {
            case 1:
                system("cls");
                ordenarGhosts(ghost, sizeGhost);
                imprimirTodosLosGhosts(ghost, sizeGhost, ghostDos, sizeGhostDos);
                break;
            case 2:
                system("cls");
                salarioPromedioGhosts(ghost,sizeGhost);
                break;
         }
     }while(opcion != 3);
 }

  /**
 * \brief busca en un array de estructura por su ID
 * \param array de estructura
 * \param tamanio del array de estructura
 * \param id establecido en la estructura
 * \return devuelve la posicion del ID, con un 0 en señal de ok, sino -1
 *
 */
 int buscarPorId(sGhost *ghost, int sizeGhost, int id)
{
    int i;
    int retorno = -1;

    if(ghost!= NULL && sizeGhost>0)
    {

        for(i=0; i<sizeGhost; i++)
        {
            if(ghost[i].id == id && ghost[i].status != STATUS_VACIO)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int mayorPeriodoFacturado(sGhost *ghost,int sizeGhost,sGhostDos *ghostDos,int sizeGhostDos)
{
    int retorno = -1;
    int i;
    int index;
    int j;
    int cantidadFacturada;
    if(ghost != NULL && sizeGhost > 0 && ghostDos != NULL && sizeGhostDos > 0)
    {
        retorno = 1; //esto nos sirve para verificar que entramos hasta aca
        for(i=0 ; i<sizeGhostDos; i++)
        {
            index = buscarPorId(ghost,sizeGhost,id);
            if(ghostDos[index].id == ghost[index].id)
            {
                HAGO LAS OPERACIONES QUE NECESITE
            }
            /*for(j=0 ; j<sizeGhost ; j++)
            {
                if(ghostDos[i].id == ghost[j].id)
                {
                    cantidadFacturada = ghostDos[i].CANTIDAD * ghost[j].ELPRECIO;
                }
            }*/

        }
    }


    return retorno;
}

int mostrarCuitFacturado(sGhost *ghost,int sizeGhost,sGhostDos *ghostDos,int sizeGhostDos,char []cuit)
{
    int retorno = -1;
    int i;
    //int index;
    int j;
    int cantidadFacturada;
    int contadorMaximo =0;
    if(ghost != NULL && sizeGhost > 0 && ghostDos != NULL && sizeGhostDos > 0)
    {
        retorno = 1; //esto nos sirve para verificar que entramos hasta aca
        for(i=0 ; i<sizeGhostDos-1; i++)
        {
            if(strcmp(ghostDos[i].CUIT,CUIT)=0)
            for(j=0 ; j<sizeGhost ; j++)
            {
                if(ghostDos[i].id == ghost[j].id)
                {
                    cantidadFacturada = ghostDos[i].CANTIDAD * ghost[j].ELPRECIO;
                    contadorMaximo = cantidadFacturada + contadorMaximo;
                }
            }

        }
    }


    return retorno;
}
