#ifndef ARREGLO_H_INCLUDED
#define ARREGLO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "Listas.h"
#include "StructsGlobales.h"

typedef struct
{
    int cargo; //1.jefe 2.encargado 3. empleado
    nodoEmpleado* listaDeArreglo;
} celda;

//prototipados
int alta(celda adlEmpleado[], int validos, empleado auxEmpleado, int cargo);
int buscarPosCargo(celda adlEmpleado[], int validos, int cargo);
int cargarCargo(celda adlEmpleado[], int validos, int cargo);

#endif // ARREGLO_H_INCLUDED
