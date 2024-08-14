#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
typedef struct {
     int dni;
     float nota;
}Alumno;

void cargarDNI(int);
void mostrarDNI();

#endif // ALUMNO_H_INCLUDED
