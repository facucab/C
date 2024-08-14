/*
CADENAS/STRINGS: Un strings es un array de caracteres.
para utilizar strings tenemos que carga la libreria correspondiente.

ACLARACION:
    * Utilizamos size_t como tipo de dato, cuando guardamos un tamaño.
    * const en cadena, refiere a que esa cadena no puede sufrir modificaciones.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    /*Declara cadenas:*/
    char cadena[5] = {"hola"};

    /* al ser arrays tienen caracteristicas que comparten */
    printf("%c", cadena[0]); // devuelve h

    /*Visualizar el codigo ascii de una letra*/
    printf("\nCODIGO ASCII: %d", cadena[3]); //devuelve 97

    /*Visualizar una cadena completa: se utiliza la submascara %s*/
    printf("\nCADENA COMPLETA: %s", cadena);

    /*FUNCIONES PARA STRINGS:*/

    /*strcpy(destino, copia): funciona para copiar dos cadenas*/
    char destino[7];
    char copia[7]= {"PRUEBA"};
    strcpy(destino, copia);
    printf("\nCADENA COPIADA: %s", destino);

    /*strlen(cadena): devuelve la longitud de una cadena*/
    char cadena2 [] = {"Probando"};
    int lon = strlen(cadena2);
    printf("\nLONGITUD DE CADENA: %d", lon);

    /*strcat(cad1,cad2): devuelve la concatenacion  de dos cadenas*/
    strcat(cadena, cadena2);
    printf("\nCADENA CONCATENADA: %s", cadena); //devuelve: holaProbando

    /*strcmp(cad1, cad2): devuelve 0 si ambas cadenas son iguales y negativo si cad1 precede cad2*/
    int comp = strcmp("abc", "abc");
    printf("\nComparacion: %d", comp);

    /*sizeof(cad) = */
    char cadPrueba[] = {"hola mundo"};
    size_t tam = sizeof(cadPrueba);
    printf("\nTAM: %d", tam);

    //Funcion recorrer
    printf("\n");
    recorrer_1("cadena");
    //Funcion recorrer inversa
    printf("\n");
    recorrerInv("cadena");
}
/*ARITMETICA DE PUNTEROS CON CADENAS*/

//recorrer
void recorrer_1(const char * cadena){
    char * cad = cadena;
    while(*cad != '\0'){
        printf("%c", *cad);
        cad++;
    }
}

// recorrer inversa
void recorrerInv(const char * cadena){
    char * cad;
    cad = cadena + strlen(cadena) - 1;
    while(*cad != '\0'){
        printf("%c", *cad);
        cad--;
    }
}
