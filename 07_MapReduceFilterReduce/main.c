/*
    Funciones: estas funciones no son nativas de C, pero se puede programar.
        Map: recorre un array, y le aplica la funcion que le pasemos como parametro a cada elemento
            Ejemplo: [1,2,3] le aplicamos una funcion map que eleve al cuadrado => [1,4,8]
            map(Funcion, array, tam elemento, num de elementos)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void * map (int (*)(void*), void*, int, size_t);
int * SumaDos(void *);
void Muestra(void *);
int main()
{
    int array[] = {1,2,3};
    int n = 3;
    int tam = sizeof(int);

    int * a = (int *)map(Muestra, array, n, sizeof(int));
    for(int i = 0; i < n ; i++)
    {
         //printf("%d\t", *(a+i));
    }

    /**/
    /*
    Ejemplo de suma dos
    int a = 6;
    void *pr = &a;
    int * pr_2 = (int * )SumaDos(pr);
    printf("%d", *pr_2);
    */
    /**/
}
int * SumaDos(void * dato)
{
    int * num = (int *)dato;
    *num++;
    return num;
}
void * map (int(*funcion)(void*), void * array, int n, size_t tam)
{
    void * aux = (void * )malloc(n  * tam);
    //Punteros
    void * pr_array = array;
    void * pr_aux = aux;
    //Recorro:
    for(int i = 0; i < n; i++)
    {
        Muestra(pr_array);
        //memcpy(pr_aux, resultado,tam); //Destino, origen, tamaño a copiar

        //Incremento todo los punteros.
        pr_array++;
        pr_aux++;
    }
    return aux;
}
void Muestra(void *dato){
    int * i = (int*)dato;
    printf("\n%d", *i);
}


/*
int * map (int (*)(int*), int *, int , int );
int * SumaDos(int * );
int main()
{
    int array_a[] = {1,6,3,8,4};
    int n = 5;
    int tam = sizeof(int);
    int * a = map(SumaDos, array_a, tam, n);
    for(int i = 0; i < n ; i++)
    {
         printf("%d\t", *(a+i));
    }

    return 0;
}
//Funcion que suma mas dos
int * SumaDos(int * dato)
{
    *dato += 2;

    return dato;
}
//Funcion map
int * map (int (*funcion)(int*), int * array, int tam , int n ){
    //reservo memoria para otro dato
    int * aux = (int *)calloc(n,tam);

    //Ptr
    int * pr_aux = (int *) aux;
    int * pr_array = (int *)array;
    for(int i = 0; i<n ; i++)
    {
        int * resultado = funcion(pr_array);

        memcpy(pr_aux, resultado, tam);
        pr_array++;
        pr_aux++;
    }
    return aux;
}
*/
