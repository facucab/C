/*
    Desarrollar una función que elimine el elemento que ocupa
    una determinada posición de un arreglo
    de enteros.
*/
#include <stdio.h>
#include <stdlib.h>
void DeletePos(int * v,int *n, int pos);
int main()
{
    int vec[5] = {1,2,3,4,5};
    int n = 5;
    DeletePos(vec, &n, 3);
    for(int i =0; i<n; i++)
    {
        printf("\n%d", vec[i]);
    }

    return 0;
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
