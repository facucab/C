/*
Funciones a crear:
    crear(); // debe inicializar el vector.
    insertPos(); inserta el elemento en la posicion dada.
    insertOrder(); insertar un elemento de manera ordenada.
    eliminarPos(); eliminar un elemento de una posicion dada.
    eliminarDup(); Eliminar duplicados.
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#define ERR_VECTOR_LLENO 2
#define DUPLICADO 1
#define ERROR 1
#define HIT 0
typedef struct
{
    int vec[TAM];
    int ce;
} Vector;

int main()
{
    Vector v; // creo la struct
    crear(&v); //utilizo la funcion crear.
    v.vec[0] = 2;
    v.vec[1] = 2;
    v.vec[2] = 4;
    v.vec[3] = 4;
    v.vec[4] = 6;
    v.vec[5] = 6;
    v.ce = 6;

    eliminarDup(&v);
    //eliminarPos(&v, 2);
    //insertPos(&v, -2, 3); Ya funciona
    //insertOrder(&v, 5);



    for(int x = 0; x< v.ce; x++)
    {
        printf("\n %d", v.vec[x]);
    }

    return 0;
}
/*eliminarDup()*/
int eliminarDup(Vector * v)  // 1 2 2 2
{
    //si el vector esta ordenado:
    for(int i = 0; i< v->ce; i++ ){
        if(v->vec[i] == v->vec[i+1]){ // si posiciones continuas tiene igual elemento

            for(int x = i; x < v->ce; x++){ // desplazo
                v->vec[x] = v->vec[x + 1];
            }
            v->ce -= 1;
        }
    }




// Si el vector esta desordenado: (REVISAR ALGORITMO)
    /*
    for(int i = 0; i< v->ce; i++)
    {
        for(int j = i +1; j < v->ce; j++)
        {
            if(v->vec[i] == v->vec[j]){
                for(int k = j ; k< v->ce ; k++){
                    v->vec[k] = v->vec[k + 1];
                }
                v->ce-=1;
            }
        }
    }
    */
}
/*eliminarPos()*/
int eliminarPos(Vector *v, int pos) //  3 4 5 :  4 3 5: 4 5
{
    if( v->ce == 0 ) return ERROR;
    for(int i = pos; i < v->ce; i++)
    {
        v->vec[i] = v->vec[i+1];
    }
    v->ce -= 1;
    return HIT;
}
/*insertOrder()*/
int insertOrder(Vector * v, int elem)
{
    if( v->ce == TAM) return ERR_VECTOR_LLENO;
    int pos = 0;
    while(pos < v->ce && elem > v->vec[pos])    // 1 2 3 5 6
    {
        pos++;
    }
    //verfico duplicados
    if(pos < v->ce && v->vec[pos] == elem)
    {
        return DUPLICADO;
    }
    //Desplazo
    for(int i = v->ce; i >= pos ; i--)  // 1 2 3
    {
        v->vec[i] =   v->vec[i - 1];
    }
    //Cargo el elemento
    v->vec[pos] = elem;
    v->ce +=1;
}
/*Funcion insertPos()*/
void insertPos(Vector * v, int elem, int pos)
{
    for(int i = v->ce; i >= pos ; i--)
    {
        v->vec[i] =   v->vec[i - 1];
    }
    v->vec[pos] = elem;
    v->ce += 1;
}
/*Funcion crear()*/
void crear(Vector *vec)
{
    vec->ce = 0;
}









/*
//TDA VECTOR
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAM 8
#define ERR_VEC 1
#define VEC_LLENO -1
#define DUPLICADO 2
//declarar vector tda:
typedef struct
{
    int vec[TAM];
    int ce;
} Vector;
bool vectorCrear(Vector * );
int vectorOrdInsert(Vector *, int);
bool vectorOrdEliminarElem(Vector *, int);
int main()
{
    Vector vector;
    if(!vectorCrear(&vector))
    {
        return ERR_VEC;
    }
    vectorOrdInsert(&vector, 2);
    vectorOrdInsert(&vector, -2);
    vectorOrdInsert(&vector, 92);
    vectorOrdInsert(&vector, 22);
    vectorOrdEliminarElem(&vector, -2);
    for(int i = 0; i< vector.ce  ; i++)
    {

        printf("\n%d", vector.vec[i]);
    }


}


bool vectorOrdEliminarElem(Vector * vec, int elem)
{
    int posElim = 0;
    while(posElim < vec->ce && elem > vec->vec[posElim])
    {
        posElim++;
    }
    if(posElim == vec->ce || elem != vec->vec[posElim])
    {
        return false;
    }

    for(int i = posElim; i < vec->ce - 1 ; i++ )
    {
        vec->vec[i] = vec->vec[i + 1];
    }
    vec->ce -=1;
    return true;
}







int vectorOrdInsert(Vector * v, int elem)
{
    if(v->ce == TAM)
    {
        return VEC_LLENO;
    }
    int posIni = 0;
    //fase de busqueda en busca de duplicados:
    while(posIni < v->ce && elem > v->vec[posIni])
    {
        posIni++;
    }

    if(posIni < v->ce && elem == v->vec[posIni])
    {
        return DUPLICADO;
    }
    for(int i = v->ce - 1; i>= posIni ; i--)
    {
        v->vec[i+1] = v->vec[i];
    }
    v->vec[posIni] = elem;
    v->ce+=1;
}

//VectorCrear: inicializa el vector tda.
bool vectorCrear(Vector * v)
{
    v->ce = 0 ;
    return true;
}
*/
