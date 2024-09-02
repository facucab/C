/*
    Desarrollar una función que elimine la primera aparición
    de un elemento determinado de un arreglo
    de enteros.

    Algoritmo:
        1° Recorro el array y encuentro la posicion del elemento. (findPos)
        2° Elimino el elemento por posicion (DeletePos).

    Funciones:

        - filterOutNumber: Filtrar/Elimina un numero que le enviamos por parametro, de un array.
            * Parametros: Recibe un array, elemento a buscar y la cantidad de elementos del array.
            * Retorna: void.

        - findPos: Devuelve la posicion de un elemento dentro de un array.
            * Parametros: Recibe un array, elemento a buscar y la cantidad de elementos del array.
            * Retorna: int con la posicion del elemento. Si no encuentra el elemento, retorna -1.

        - DeletePos: Elimina un elemento de un array, por su posicion.
            * Parametros: Recibe un array, un puntero con la cant de elementos y la posicion a eliminar.
*/

#include <stdio.h>
#include <stdlib.h>
void filterOutNumber(int * v, int e, int *n);
int findPos(int * v, int e, int n);
void DeletePos(int * v, int *n, int pos);
int main()
{
    int vec[5] = {1,2,3,4,5};
    int n = 5;
    int e = 4;
    filterOutNumber(vec, e, &n);

    /*
    ///Muestra
    for(int i = 0; i < n; i++)
    {
        printf("\n%d", vec[i]);
    }
    */
}

void filterOutNumber(int * v, int e, int *n)
{
    int pos = findPos(v, e, *n);

    if(pos != -1)
    {
        DeletePos(v, n, pos);
        printf("El numero %d fue removido con exito!\n", e);
    }
    else{
        printf("El numero %d no fue encontrado!!!\n",e);
    }
}
int findPos(int * v, int e, int n)
{
    int * pr_v = v;
    int pos = 0;

    while( *pr_v != e && pos < n )
    {
        pos++;
        pr_v++;
    }

    return (pos < n) ? pos : -1;
}
void DeletePos(int * v, int *n, int pos)
{
    int * pr_v = v;
    for(int i = pos; i< *n -1; i++)
    {
        *(pr_v + i) = *(pr_v + 1 + i );

    }
    *n-=1;
}

