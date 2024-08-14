/*
    Funciones de biblioteca:
        Ordenamiento: qsort(array, cantidad de elementos de array, tamaño de elemento, funcion de comparacion).
            La funcion campare = es una funcion de comparacion entre dos variables

        Busqueda: bsearch(*elemento, array, num_elem, tam_elem, compare)

    Creacion de funciones independientemente del tipo dato:
        * Con macros: (Esta explicado en el archivo)
        * Con puntero a funcion.
*/
#include <stdio.h>
#include <stdlib.h>
#define SUMA(a,b) a+b

int compare(void * , void * );
int main(){
    /*Funcion qsort*/
    int array [] = {5,67,7,8,-12,-34};
    int n = 6;
    //llamamos a qsort
    qsort(array,n, sizeof(int), compare);

    //Muestra del array
    for(int i = 0; i<n; i++)
    {
        printf("\t%d",array[i]);
    }
    /*Funcion bsearch*/
    int array_b [] = {6,7,1,-31,32,-13};
    int elem = 32;
    int * resultado = (int * )bsearch(&elem, array_b, n, sizeof(int), compare);
    if(resultado != NULL)
    {
        printf("\nEl elemento %d se encontro en la posicion: %d", elem, (int)(resultado - array_b));
    }

    /*Creacion de funciones independientemente del tipo dato:*/
    //con macros
    int r = SUMA(5,6);
    printf("\nLa suma de int es %d", r);
    float r_2 = SUMA(5.5,4);
    printf("\nLa suma de float es %f", r_2);

}
// Funcion compare (existen otras formas de pensarla)
int compare(void * x , void * y){
    int * a = (int*)x; //
    int * b = (int*)y;
    if(*a > *b) return 1;
    if(*a < *b) return -1;
    return 0;
}
