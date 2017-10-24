#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

int cargarPelicula(ePelicula* peliculas, int* contador)
{
    int flag = 0;
    FILE* arch;

    arch = fopen("pelis.dat", "rb");

    if(arch == NULL)
    {
        arch = fopen("pelis.dat", "wb");

        if(arch == NULL)
        {
            return 1;
        }
        flag = 1;
    }
    if(flag == 0)
    {
        fread(contador,sizeof(int),1,arch);

        while(!feof(arch))
        {
            fread(peliculas,sizeof(ePelicula),*contador,arch);
        }
    }
    fclose(arch);

    return 0;
}

int agregarPelicula(ePelicula* pelicula,int cont,int* puntCont)
{
    int lugar;
    int i;
    char auxTitulo[40];
    char auxGenero[30];
    char auxDescripcion[150];
    char linkImagen[200];
    int duracion;
    int puntaje;
    int repetido = 0;

    lugar = cont-1;

    printf("Ingrese el titulo: ");
    fflush(stdin);
    scanf("%s", auxTitulo);

    for(i = 0 ; i < cont ; i++)
    {
        if(strcmp(auxTitulo,(pelicula+i)->titulo)==0 && (pelicula+i)->duracion!=0)
        {
            repetido = 1;
            break;
        }
    }
    if(repetido == 0)
    {
        strcpy((pelicula+lugar)->titulo,auxTitulo);

        printf("Ingrese genero: ");
        fflush(stdin);
        gets(auxGenero);
        strcpy((pelicula+lugar)->genero,auxGenero);

        printf("Ingrese duracion en minutos: ");
        fflush(stdin);
        scanf("%d",&duracion);

        printf("Ingrese descripcion: ");
        fflush(stdin);
        gets(auxDescripcion);

        printf("Ingrese puntaje: ");
        fflush(stdin);
        scanf("%d",&puntaje);

        printf("Ingrese el link de la imagen: ");
        fflush(stdin);
        gets(linkImagen);

        (pelicula+lugar)->duracion = duracion;
        strcpy((pelicula+lugar)->descripcion,auxDescripcion);
        (pelicula+lugar)->puntaje = puntaje;
        strcpy((pelicula+lugar)->linkImagen,linkImagen);
    }
    else
    {
        printf("El titulo ingresado esta repetido.\n");
        *puntCont-=1;
    }
}

void borrarPelicula(ePelicula* pelicula,int contador)
{
    int flag = 0;
    int i;
    char titulo[40];
    char opcion;

    printf("\nLista Peliculas\n\n");

    for(i = 0 ; i < contador ; i++)
    {
        if((pelicula+i)->duracion!=0)
        {
            printf("%s\n",(pelicula+i)->titulo);
        }
    }
    printf("Ingrese el titulo de la pelicula que desee eliminar: ");
    fflush(stdin);
    scanf("%s", titulo);

    for(i=0 ; i < contador ; i++)
    {
        if(stricmp(titulo,(pelicula+i)->titulo)==0 && (pelicula+i)->duracion!=0)
        {
            printf("Pelicula a eliminar:\n");

            printf("Titulo :%s\nGenero: %s\nDuracion: %d Minutos\nDescripcion: %s\nPuntaje: %d\nLink de la imagen: %s\n", pelicula->titulo, pelicula->genero, pelicula->duracion, pelicula->descripcion, pelicula->puntaje, pelicula->linkImagen);

            printf("\nSeguro desea eliminar esta pelicula s/n?: ");
            opcion = getche();
            if(opcion == 's')
            {
                (pelicula+i)->duracion = 0;
                printf("\nPelicula eliminada.\n");
            }
            else
            {
                printf("\nAccion cancelada.\n");
            }
            flag = 1;
            break;
        }
    }
    if(flag==0)
    {
        printf("Pelicula no cargada.\n");
    }
}
void modificarPelicula(ePelicula* pelicula,int contador)
{
    int flag = 0;
    int opcion;
    int lugar;
    int i;
    char auxTitulo[40];
    char auxGenero[30];
    char auxDescripcion[150];
    char linkImagen[200];
    int duracion;
    int puntaje;
    int repetido=0;

    printf("Lista peliculas\n");

    for(i = 0 ; i < contador ; i++)
    {
        if((pelicula+i)->duracion!=0)
        {

            printf("%s\n",(pelicula+i)->titulo);
        }
    }
    printf("Ingrese pelicula a modificar: ");
    fflush(stdin);
    scanf("%s", auxTitulo);

    for(i=0; i<contador; i++)
    {
        if(strcmp(auxTitulo,(pelicula+i)->titulo)==0 && (pelicula+i)->duracion!=0)
        {
            printf("Pelicula a modificar:\n");

            printf("Titulo :%s\nGenero: %s\nDuracion: %d Minutos\nDescripcion: %s\nPuntaje: %d\nLink de la imagen: %s\n", pelicula->titulo, pelicula->genero, pelicula->duracion, pelicula->descripcion, pelicula->puntaje, pelicula->linkImagen);

            lugar=i;
            printf("\nElija el campo a modificar: \n");

            printf("1.Titulo\n");
            printf("2.Genero\n");
            printf("3.Duracion en minutos \n");
            printf("4.Descripcion\n");
            printf("5.Puntaje\n");
            printf("6.Link a imagen\n");
            fflush(stdin);
            scanf("%d",&opcion);


            switch(opcion)
            {
            case 1:
                printf("Ingrese el nuevo titulo: ");
                fflush(stdin);
                scanf("%s", auxTitulo);


                for(i = 0 ; i < contador ; i++)
                {
                    if(strcmp(auxTitulo,(pelicula+i)->titulo) == 0 && (pelicula+i)->duracion!=0)
                    {
                        repetido = 1;
                        break;
                    }
                }
                if(repetido = 0)
                {
                    strcpy((pelicula+lugar)->titulo,auxTitulo);
                    printf("Titulo modificado.\n");
                }
                else
                {
                    printf("El Titulo ingresado no existe.\n");
                }
                break;
            case 2:
                printf("Ingrese el nuevo genero: ");
                fflush(stdin);
                gets(auxGenero);

                strcpy((pelicula+lugar)->genero,auxGenero);

                printf("\nGenero modificado.\n");
                break;
            case 3:
                printf("Ingrese la nueva duracion en minutos: ");
                fflush(stdin);
                scanf("%d",&duracion);

                (pelicula+lugar)->duracion=duracion;

                printf("\nDuracion modificada.\n");
                break;
            case 4:
                printf("Ingrese la nueva descripcion: ");
                fflush(stdin);
                gets(auxDescripcion);

                strcpy((pelicula+lugar)->descripcion,auxDescripcion);

                printf("\nDescripcion modificada.\n");
                break;
            case 5:
                printf("Ingrese el nuevo puntaje: ");
                fflush(stdin);
                scanf("%d",&puntaje);

                (pelicula+lugar)->puntaje = puntaje;

                printf("\nPuntaje modificado.\n");
                break;
            case 6:
                printf("Ingrese el nuevo link de la imagen: ");
                fflush(stdin);
                gets(linkImagen);

                strcpy((pelicula+lugar)->linkImagen,linkImagen);

                printf("\nLink modificado.\n");
                break;
            default:
                printf("Opcion invalida.\n");
                break;
            }

            flag = 1;
            break;
        }



    }
    if(flag == 0)
    {
        printf("No se pudo cargar la pelicula\n");
    }
}

void crearPagina(ePelicula* pelicula,int contador,char html[])
{
    FILE* arch;
    int i;

    strcat(html,".html");
    arch = fopen(html,"w");

    if(arch == NULL)
    {
        printf("No se pudo crear el archivo");
        exit(1);
    }

    fprintf(arch,"<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>");

    for(i = 0 ; i < contador ; i++)
    {
        if((pelicula+i)->duracion!=0)
        {
            fprintf(arch,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a>\n",(pelicula+i)->linkImagen);
            fprintf(arch,"<h3><a href='#'>%s</a></h3>\n",(pelicula+i)->titulo);
            fprintf(arch,"<ul><li>Genero:%s</li>\n<li>Puntaje:%d</li>\n<li>Duracion:%d</li></ul>\n",(pelicula+i)->genero,(pelicula+i)->puntaje,(pelicula+i)->duracion);
            fprintf(arch,"<p>%s</p></article>",(pelicula+i)->descripcion);
        }
    }

    fprintf(arch,"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");

    fclose(arch);
}

int guardar(ePelicula* pelicula,int contador,int* puntContador)
{
    FILE* arch;

    arch = fopen("pelis.dat","wb");

    if(arch == NULL)
    {
        return 1;
    }
    fwrite(puntContador,sizeof(int),1,arch);

    fwrite(pelicula,sizeof(ePelicula),contador,arch);

    fclose(arch);

    return 0;
}
