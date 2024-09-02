/*
    Ejercicio 1.5
    Desarrollar una función que elimine todas las apariciones de un determinado
    elemento de un arreglo de enteros.

    Algoritmo:
        1° Recorro el array, verifico la posicion del elemento a eliminar.
        2° Elimino el elemento con la posicion. (Si elimino NO incremento index, porque se redujo el vector
                                                    y se cambia la posicion)

    Funciones:

        - removeNumber: Elimina todas la ocurrencias de un numero en un array.
            * Parametros: Recibe un vector, un elemento a eliminar y el tamaño del vector.
            * return: void.

        - DeletePos: Elimina un elemento de un array, por su posicion.
            * Parametros: Recibe un array, un puntero con la cant de elementos y la posicion a eliminar.

*/
#include <stdio.h>
#include <stdlib.h>
void removeNumber(int * vec, int e, int *sizeVec);
void DeletePos(int * v, int *sizeVec, int pos);
int main()
{
    int vec[5] = {1,2,2,24,2};
    int n = 5;
    int e = 2;
    removeNumber(vec, e, &n);


    ///Mostrar
    for(int i = 0; i< n; i++)
    {
        printf("\n%d", vec[i]);
    }

    return 0;
}
void removeNumber(int * vec, int e, int *  sizeVec)
{
    int index = 0;
    int * pr_vec = vec;

    while(index < *sizeVec)
    {
        if(* (vec + index)  == e)
        {
            DeletePos(vec, sizeVec, index);
        }
        else
        {
            index++;
        }
    }
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

