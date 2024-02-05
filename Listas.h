#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "StructsGlobales.h"


typedef struct
{
    empleado dato;
    struct nodoEmpleado* siguiente;
} nodoEmpleado;

typedef struct
{
    char dato;
    struct nodoDoble* ante;
    struct nodoDoble* sig;
} nodoDoble;

///Prototipados
//Lista Simple para el Arreglo De Listas
nodoEmpleado* inicLista();
nodoEmpleado* crearNodo(empleado datos);
nodoEmpleado* agregarPpio(nodoEmpleado* lista, nodoEmpleado* nuevoNodo);
//Lista Doble para Las Filas
nodoDoble* inicListaDoble();
nodoDoble* crearNodoDoble(char datos);
nodoDoble* agregarFinalDoble(nodoDoble* lista, nodoDoble* nuevoNodo);
nodoDoble* borrarPrimerNodoDoble(nodoDoble* lista);
char verPrimero(nodoDoble* lista);
void recorrerYmostrarDoble(nodoDoble* lista);
void escribir(nodoDoble* aux);

#endif // LISTAS_H_INCLUDED
