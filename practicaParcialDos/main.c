#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "Cachorros.h"

int main()
{
    int option;
	int flag = 0;

	LinkedList* pAarrayPuppyList;
	pAarrayPuppyList = ll_newLinkedList();


	do{
        system("cls");
	    printf(	 "Menu:\n\n"
				 "1. Cargar archivo\n"
				 "2. Imprimir lista\n"
				 "3. Filtrar menores de 45 dias(generar archivo)\n"
				 "4. Filtrar machos(generar archivo)\n"
				 "5. Generar listado de callejeros\n"
				 "6. Salir\n");

	    getInt(&option,"Elija una opcion\n","Opcion invalida\n",0,6,2);

	        switch(option)
	        {
	            case 1:

	                if(flag == 0)
	                {
                        if(parser_parserCachorros("cachorros.csv",pAarrayPuppyList)==1)
                        {
                           printf("Lista cargada con exito\n");
                           flag = 1;
                           system("pause");
                        }

	                }
	                else
	                    {
	                        if(flag == 1)
	                        {
	                            printf("Ya se cargaron los archivos\n");
	                            system("pause");
	                        }
	                    }

	                break;
	            case 2:
	                if(flag == 1)
	                {
	                	cachorro_imprimirTodosLosCachorros(pAarrayPuppyList);
	                	system("pause");
	                }
	                else
	                {
	                	printf("Debe cargar un archivo primero\n");
	                	system("pause");
	                }
	            	break;
	            case 3:
                    cargarListaFiltradaMenoresDias(pAarrayPuppyList);
                    printf("Archivo cargado con exito\n");
                    system("pause");
	            	break;

	            case 4:
                    cargarListaFiltradaGenero(pAarrayPuppyList);
                    printf("Archivo cargado con exito\n");
                    system("pause");
	                break;

	            case 5:
                    imprimirListaFiltradaCallejero(pAarrayPuppyList);
                    system("pause");
	                break;

	        }
	    }while(option != 6);
    return 0;
}
