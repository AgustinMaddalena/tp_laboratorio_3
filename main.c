#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

int main()
{
    ePelicula* listado;
    int contadorPeli = 0;
    int* puntPeli = &contadorPeli;
    char html[50] = {"Lista de Peliculas"};
    char seguir = 's';
    int opcion = 0;
    int i;

    listado = (ePelicula*) malloc(sizeof(ePelicula)*50);

    if(listado == NULL)
    {
        printf("\nNo hay espacio disponible.");
        exit(1);
    }

    for(i=0 ; i<contadorPeli ; i++)
    {
        listado->duracion = 0;
        listado->puntaje = 0;
    }

    if (cargarPelicula(listado,puntPeli) == 1)
    {
        printf("\nEl Archivo No Pudo Abrirse.");
    }

    while(seguir=='s')
    {
        system("color 3");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            if(contadorPeli % 50 == 0)
            {
                contadorPeli++;
                ePelicula* auxPelis;

                auxPelis = (ePelicula*) realloc(listado,sizeof(ePelicula)*50);

                if(auxPelis == NULL)
                {
                    exit(1);
                }
                else
                {
                    listado = auxPelis;
                    agregarPelicula(listado,contadorPeli,puntPeli);
                }
            }
            else
            {
                system("cls");
                contadorPeli++;
                agregarPelicula(listado,contadorPeli,puntPeli);
            }
            break;
        case 2:
            system("cls");
            borrarPelicula(listado,contadorPeli);
            break;
        case 3:
            system("cls");
            modificarPelicula(listado,contadorPeli);
            break;
        case 4:
            system("cls");
            crearPagina(listado,contadorPeli,html);

            if(guardar(listado,contadorPeli,puntPeli))
            {
                printf("\nNo pudo abrirse el archivo.\n");
            }
            break;
            case 5:
            seguir = 'n';
            break;
        }
    }

    return 0;
}
