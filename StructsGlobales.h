#ifndef STRUCTSGLOBALES_H_INCLUDED
#define STRUCTSGLOBALES_H_INCLUDED

typedef struct
{
    char nombreYApellido[50];
    int codigoDeEmpleado;
    char sectorAsociado[50];
    int telefono;
    int DNI;
    int cargo; //1.jefe 2.encargado 3.empleado
} stDatosArchivo;

typedef struct
{
    char nombreYApellido[50];
    int codigoDeEmpleado;
    char sectorAsociado[50];
    int telefono;
    int DNI;
} empleado;

#endif // STRUCTSGLOBALES_H_INCLUDED
