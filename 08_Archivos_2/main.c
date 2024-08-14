/*
    Archivos de texto: Dos tipos de archivos de texto.
        * Longitud fija: Tienen caracteres fijos de separacion entre datos.
        * Longitud variable: Cada dato tiene una longitud variable y se utilizan separadores (|)

    Funciones para archivos:
        * fprintf(): Escribe sobre un archivo texto.
        * fscanf(): Lee datos de un archivo de texto.
        * fgets(): Lee lineas de texto de un arch txt.
        * fputs(): Escribe un linea de texto en arch txt.
        * sscanf(): Lee los datos desde una cadena.

    ESTE ARCHIVO INCLUYE:
        * Escritura de un archivo txt de long variable.
        * Trozeo de archivo de txt de long variable.
        * Lectura y Escritura de un archivo txt de long fija.
        * Trozeo de archivo de txt de long fija.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int legajo;
    char nombre[15];
}Empleado;
void EscriturarFija(const char *);
void TrozearFija(Empleado *, char * );
void Lectura(const char *);
int main(int argc, const char * argv[])
{
    //EscriturarFija(argv[1]);
    Lectura(argv[1]);
    return 0;
}

//Escritura de arch longitud fija: 2 caracteres para el legajo y 15 para el nombre
void EscriturarFija(const char * nombre)
{
    FILE * arch = fopen(nombre, "wt");
    if(!arch) printf("ERROR EN LA APERTURA DEL ARCHIVO: %s", nombre);

    Empleado emp[5] =
    {
        {1,"facu"},
        {2,"zoe"},
        {3,"messi"},
        {4,"neymar"},
        {50,"suarez"},
    };

    for(int i=0; i<5; i++)
    {
        fprintf(arch, "%-15s%2d\n",emp[i].nombre, emp[i].legajo);
    }
    fclose(arch);
}

// Trozeo de archivo de longitud fija
void TrozearFija(Empleado * emp , char * linea )
{
    char * aux = (linea + 17);
    *aux = '\0';
    aux-=2;
    sscanf(aux, "%2d", &emp->legajo);
    //
    strncpy(emp->nombre, linea, 15);
    emp->nombre[15] = '\0';
}

//LECTURA DE ARCHIVO DE TEXTO
void Lectura(const char * nombre)
{
    FILE * arch = fopen(nombre, "rt");
    if(!arch) printf("ERROR EN LA APERTURA");

    char aux[100];
    Empleado emp;
    while( fgets(aux, sizeof(aux) , arch)  ) // != NULL
    {
        TrozearFija(&emp,aux);
        //Muestra la struct
        printf("Legajo: %d\tNombre:%s\n", emp.legajo, emp.nombre);
    }
    fclose(arch);
}
