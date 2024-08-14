/*
    Pasaje de parametros: dos formas de pasar por parametro en c.
        * Pasaje de parametros por valor (por copia):
            Cuando pasamos por copia el valor de variable SOLO
            se modifica dentro del scope de la funcion.
            Se mantiene el original en el main.
        * Pasaje de parametros por referencia o dirreccion:
            Cuando pasamos una la direccion de una variable, se modifica
            en el scope del main y de la funcion.
        
    Puntero a Funcion: Es un puntero que apunta a una funcion.
*/
#include <stdio.h>
#include <stdlib.h>
int PasajePorCopia(int);
void PasajePorReferencia(int *);
int suma(int, int);
int resta(int , int);
//Operacion
int Operacion(int, int, int (*) (int, int));
int main()
{
  //Pasaje de parametros por copia o valor:
  int x = 5;
  PasajePorCopia(x);
  printf("El valor de x: %d se mantiene", x); // Se mantiene dado que solo le paso una copia de x

  // Pasaje por direccion o referencia:
  int num = 10;
  printf("\nValor original de num: %d", num);
  PasajePorReferencia(&num);
  printf("\nValor modificado de num; %d", num);

    //Puntero Funcion:
    int (*puntero_funcion)(int, int); //creacion de un puntero a funcion
    puntero_funcion = &suma;
    int a = puntero_funcion(3,4);
    printf("\nPuntero a funcion: %d", a);

    //Aplicacion de un puntero a funcion
    /*
        Creamos una funcion que se llame operacion y reciba como parametros:
         dos numero, un puntero funcion
    */
    int suma_r = Operacion(7,8,&suma);
    printf("\nEl resultado de la suma es: %d", suma_r);

    int resta_r = Operacion(7,8,&resta);
    printf("\nEl resultado de la resta es: %d", resta_r);

    //La idea de puntero a funcion es que con una misma funcion podes realizar dos funciones distintas( o mas)


}
//Funcion 1:
int PasajePorCopia(int num ){
    return num+1000;
}
//Funcion 2:
void PasajePorReferencia(int * n){
    *n+=2;
}
//Funcion 3:
int suma(int x, int y){
    return x + y ;
}
//Funcion 4:
int resta(int x , int y){
    return x - y;
}
//Funcion5:
int Operacion(int x, int y, int (*funcion)(int, int)){
    return funcion(x,y);
}
