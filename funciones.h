#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct
{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];

} ePelicula;

int cargarPelicula(ePelicula*,int*);

int agregarPelicula(ePelicula*,int,int*);

void borrarPelicula(ePelicula*,int);

void modificarPelicula(ePelicula*,int);

void crearPagina(ePelicula*,int,char[]);

int guardar(ePelicula*,int,int*);

#endif // FUNCIONES_H_INCLUDED
