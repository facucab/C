#include <stdio.h>
#include <stdlib.h>
//Memoria Dinamica: Es la memoria que se asigna en tiempo de ejecucion de un programa.
/*
    Tres funciones para trabajar con memoria dinamica:
    malloc(n * Tamaño): Asigna un bloque de memoria especifico en bytes.
    calloc(n, Tamaño): Asigna un bloque de memoria en bytes, pero inicializa en cero.
    realloc(puntero, n * Tamaño):

    ACLARACION: si no hay memoria posible, devuelve NULL
    free(puntero): SIEMPRE SE USA, libera los recurso de la memoria
*/
int main()
{
    //Como crear un malloc()
    int * ptr;
    int cantidadDeElem = 1;
    ptr = (int *)malloc(cantidadDeElem * sizeof(int) ); //malloc SIEMPRE se castea
    //como crear un calloc
    int * ptrCalloc;
    int cantCalloc = 2;
    ptrCalloc = (int*)calloc(cantCalloc, sizeof(int));

    //Ejemplo de realloc()
    int * ptrRealloc;
    ptrRealloc = (int*)malloc(999999999999999 * sizeof(int));
    if(ptrRealloc == NULL ){
        //La memoria se agoto
         ptrRealloc = (int*)realloc(ptrRealloc, 5*sizeof(int) );
    }
    if(ptrRealloc != NULL){
        printf("se realoco la memoria");
    }
    //LIBERAR RECURSO DE LA MEMORIA

    free(ptr);
    free(ptrCalloc);
    free(ptrRealloc);

}
