/*
    Archivos: Existen dos tipos de flujos (Archivo binario y de texto).


    Apertura de archivos: Para la apertura de archivos necesitamos crear un puntero de
        tipo FILE y utilizamos la funcion:
        fopen(const char * nombreFisicoDelArch, const char * modoDeApertura)

    Modos de apertura:
        * "rb" "rt": Es para lectura, se ubica al inicio del archivo y si no encuentra devuelve NULL
        * "wb" "wt": Es para escritura, se ubica al inicion y si no existe lo crea, o lo deja en vacio.
        * "ab" "at": Se ubica al final y si no existe lo crea, ubicandose el inicio.

    Cierre de archivos: Siempre es obligatorio cerrar archivos, se utiliza:
    fclose(NombreLogicoDelArchivo)

    Aclaracion:
    FILE * NombreLogico = fopen(NombreFisico, ModoApertura);

    Funciones mas utilizadas para archivos:
        * fopen(): Apertura de archivos.
        * fclose(): Cierre de archivos.
        * feof(): Devuelve =!0 si se llego al final del archivo.
        * fseek(): Nos permite desplazarnos por el archivo.
        * ftell(): Nos da la cantidad de bytes desde el inicio hasta el puntero.
        * rewind(): Vuelvo el puntero al inicio del archivo.
        * remove(): Elimina el archivo.
        * rename(): Renombra al archivo.

    Archivos Binarios: Son archivos que no se pueden leer la informacion grabado con solo abrirlos.
        Por convencion se crean con extesion .dat, pero esto no afecta,
        se puede crear con cualquiera extesion (.bin, .txt, .aux)

    Aclaracion: Para los nombres de los archivos, usamos argumentos al main.

    ESTE ARCHIVO CONTIENE:
        * Lectura de archivos binarios.
        * Escritura de archivos binarios.
        * Calcular tamaño de archivo binarios (Sin recorrer).
        * Crear lotes de prueba archivos binarios.
        * Ordenar un archivo binario.
*/

#include <stdio.h>
#include <stdlib.h>
void CargaBin(const char *); //Funcion para Cargar.
void LecturaBin(const char *);
size_t TamArch(const char *);
void CrearPersonas(const char *);
void Ordenar(const char *);
typedef struct
{
    int dni;
    char nombre[20];
} Persona;
void OrdenarStruct(Persona *, size_t);
int main(int argc, char *argv[])
{
    //CargaBin(argv[1]);
    //LecturaBin(argv[1]);
    /*
    size_t tam = TamArch(argv[1]);
    printf("\nLa cantidad de registro en el archivo son: %d", tam/sizeof(Persona));
    */
    //CrearPersonas(argv[1]);

    //Ordenar(argv[1]);

    return 0;
}
/*
    Funcion para ordenar archivo binario por dni:
*/
void Ordenar(const char *nombre)
{
    size_t tam = TamArch(nombre) / sizeof(Persona);
    FILE * arch = fopen(nombre, "rb");
    if(!arch)
    {
        printf("ERROR EN LA APERTURA");
    }

    Persona * pen = (Persona *)malloc(tam * sizeof(Persona));
    Persona * pr_pen = pen;
    fread(pr_pen, sizeof(Persona),1,arch);

    while(!feof(arch))
    {
        pr_pen++;
        fread(pr_pen, sizeof(Persona),1,arch);
    }
    fclose(arch);

    //ORDENO struct
    OrdenarStruct(pen,tam);

    //Grabar en el archivo.
    FILE * archGrabar = fopen(nombre, "wb");
    if(!archGrabar) printf("ERROR");
    fwrite(pen, sizeof(Persona), tam, archGrabar);
    fclose(arch);
    free(pen);
}

void OrdenarStruct(Persona * p, size_t tam)
{
    //Ordenar el vector de struct
    Persona * ord_pen = p;
    Persona aux;
    for(int i = 0; i<tam; i++)
    {
        for(int j = 0; j<tam-1; j++)
        {
            if( (ord_pen + j)->dni > (ord_pen + j + 1)->dni)
            {
                aux = *(ord_pen+j+1);
                *(ord_pen+j+1) = *(ord_pen+j);
                *(ord_pen+j) = aux;
            }
        }
    }
}
void CrearPersonas(const char *nombre)
{
    FILE * arch = fopen(nombre, "wb");
    if(!arch)
    {
        printf("ERROR EN LA APERTURA");
    }
    Persona per[5] =
    {
        {4,"Facundo"},
        {1,"Zoe"},
        {2,"Messi"},
        {8,"Cristiano"},
        {5,"Neymar"}
    };
    fwrite(per, sizeof(Persona),5, arch);
    fclose(arch);
}
/*
    FUNCION PARA CALCULAR EL TAMAÑO DE UN ARCHIVO: Para esto usamos fseek: moviendo el puntero al final.
        Luego fteel para calcular el tamaño desde el inicio a la posicion del puntero.
*/
size_t TamArch(const char * nombre)
{
    FILE * arch = fopen(nombre, "rb");
    if(!arch)
    {
        printf("ERROR EN LA APERTURA DE ARCHIVO: %s", nombre);
    }
    fseek(arch, 0, SEEK_END);
    size_t tam = (size_t)ftell(arch);
    fclose(arch);
    return tam;
}
/*
    FUNCION PARA LECTURA DE ARCHIVOS BINARIOS: se utilza la funcion
    fread(punteroDato, tamaño, cantidad, nombreLogico);
*/
void LecturaBin(const char * nombre)
{
    FILE * arch = fopen(nombre, "rb"); //Modo de apertura, para lectura.
    if(!arch)
    {
        printf("\nError en la apertura de archivo %s", nombre);
    }
    Persona pen;
    fread(&pen, sizeof(Persona),1,arch);
    //recorro el archivo
    while(!feof(arch))
    {
        printf("Nombre: %s\tDni:%d\n", pen.nombre, pen.dni);
        fread(&pen, sizeof(Persona),1,arch);
    }
    fclose(arch);
}

/*
    FUNCION PARA CARGA DE ARCHIVOS BINARIOS: Se utiliza la funcion
        fwrite(punteroDelDato, tamaño, cantidad, NombreLogico);
*/
void CargaBin(const char * nombre)
{
    FILE * arch = fopen(nombre, "wb"); // Lo abrimos en modo lectura
    if(arch == NULL) //SIEMPRE HAY QUE VALIDAR LA APERTURA.
    {
        printf("ERROR EN LA APERTURA DEL ARCHIVO: %s ", nombre);
    }
    Persona pen;//En este caso cargamos dos persona
    for(int i = 0; i<2; i++)
    {
        //carga de datos en la struct
        printf("Ingrese un DNI: \n");
        scanf("%d", &pen.dni);
        fflush(stdin);
        printf("Ingrese un nombre: \n");
        gets(pen.nombre);

        //Cargar en el archivo
        fwrite(&pen, sizeof(Persona),1, arch);
    }
    fclose(arch); //Cierre de archivos
}
