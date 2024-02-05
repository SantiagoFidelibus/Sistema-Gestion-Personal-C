#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "Listas.h"
#include "StructsGlobales.h"

typedef struct{
    empleado dato;
    struct nodoArbol* izq;
    struct nodoArbol* der;
}nodoArbol;

//Prototipados:
nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(empleado dato);
nodoArbol* insertarAlArbolEnOrden(nodoArbol* arbol, empleado a);
void inorden(nodoArbol* arbol);

#endif // ARBOL_H_INCLUDED
