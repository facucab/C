#include <stdio.h>
#include <stdlib.h>
/*
        Punteros: son variables donde se almacenan dirrecciones memorias.
*/
typedef struct {
    int dia;
    int mes;
    int anio;
}Fecha;

int main()
{
    /*Declaracion de puntero*/
    int * nombrePuntero; // para declarar un puntero se utiliza *

    /*Declaracion incorrecta de punteros */
    //int * Puntero , var; solo la variable Puntero se comportaria como puntero.

    /*Operador & devuelve la dirreccion de memoria de una variable u objetos*/
    int * punteroX, valorX = 10;
    punteroX = &valorX; // en punteroX guarda la dirrecion de memoria de valorX.

    /*Mostrar punteros*/
    printf("%p", punteroX);
    *punteroX -= 3; // Modificamos la variable ValorX a traves de un puntero.
    printf("\n%d", valorX); // devuelve 7

    /*
    Aritmetica Puntero con arrays:
    Los punteros puede moverse sumando o decrementando a traves de las dirrecciones
    de memoria.
    */
    int vec[5] = {-31,20,3,4}; //Los vectores son dirrecciones continuas de memoria, pero no se puede utilizar aritmetica de puntero direcmente sobre ellos
    /*Ejemplo de como NO usar Aritmetica de punteros con vectores*/
    //*vec = *vec + 10; ESTO ES UN ERROR, NO COMPILA.

    /*Ejemplo de la manera CORRECTA para usar aritmetica de punteros*/
    int * punteroVec = vec; // en punteroVec cargue de vec
    punteroVec+=1; // ahora es posible moverse a traves del vector con el puntero.
    printf("\n%d", *punteroVec); // muestra el 20

    /*Ejemplo de carga de valores con un vector (Utilizando aritmetica de punteros)*/
    int vectorNum [4] = {0};
    int * PunteroVecNum = vectorNum;
    * PunteroVecNum = 34;
    for(int i = 0; i<3; i++){
        printf("Ingrese un Numero: \n");
        scanf("%d", PunteroVecNum);
        PunteroVecNum += 1 ;
    }
    // ACLARACION: PunteroVecNum queda en la ultima posicion + 1 de vectorNum

    /*Ejemplo recorre un vector con aritmetica de punteros*/
    int * PunteroMostrarNum = vectorNum;
    for(int i = 0; i<3; i++){
        printf("\n%d", * (PunteroMostrarNum + i ) );
    }

    /*PUNTEROS CON STRUCTS*/
    Fecha f; //declaro la struct para ejemplos.
    /*declarar puntero para struct*/
    Fecha * prFecha = &f; //SIEMPRE LLEVA & PORQUE DEBE APUNTAR A LA DIRRECCION DE MEMORIA DE LA STRUCT

    /*Modificar valores por el puntero*/
    (*prFecha).dia = 8;  //Opcion 1 ) (*Nombre).propiedad
    prFecha->mes  = 10; //Opcion 2 nombre->propiedad (La mejor manera)
    prFecha->anio = 2002;

    /*Mostrar la struct con un puntero*/
    printf("\n%d / %d / %d", prFecha->anio, prFecha->mes, prFecha->dia);
    return 0;
}
