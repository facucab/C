/*
    Ejercicio 1.1)
    Desarrollar una función que inserte un elemento en un arreglo
    de enteros, dada la posición de inserción.
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 5
void InsertNumberPos(int * v, int pos, int e);
void PrintVec(int * v);
int main()
{
    int vec[5] = {1,2,3,4,5};
    int e = -9;
    InsertNumberPos(vec, 1, e);
    PrintVec(vec);

}
void InsertNumberPos(int * v, int pos, int e)
{
    int * pr_v = v + TAM;
    int * aux = v;
    //Desplazamos:

    for(int i = TAM - 1; i > pos; i--)
    {
        *pr_v = *(pr_v - 1);
    }

    * (aux + pos) = e;

}


void PrintVec(int * v)
{
    int * pr_v = v;
    for(int i = 0; i < TAM; i++)
    {
        printf("%d\n", *(pr_v + i ));
    }
}
