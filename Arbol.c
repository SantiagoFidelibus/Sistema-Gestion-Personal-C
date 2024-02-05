#include "Arbol.h"

nodoArbol* inicArbol()
{
    return NULL;
}

nodoArbol* crearNodoArbol(empleado dato)
{
    nodoArbol* aux = (nodoArbol*) malloc(sizeof(nodoArbol));
    aux->dato = dato;
    aux->der = NULL;
    aux->izq = NULL;
    return aux;
}

nodoArbol* insertarAlArbolEnOrden(nodoArbol* arbol, empleado a)
{
  if (arbol == NULL) {
    arbol = crearNodoArbol(a);
  } else {
    if (a.codigoDeEmpleado < arbol->dato.codigoDeEmpleado) {
      arbol->izq = insertarAlArbolEnOrden(arbol->izq, a);
    } else {
      arbol->der = insertarAlArbolEnOrden(arbol->der, a);
    }
  }
  return arbol;
}

void inorden(nodoArbol* arbol)
{
    if (arbol != NULL) {
        inorden(arbol->izq);
        printf("\n- %s", arbol->dato.nombreYApellido);
        inorden(arbol->der);
    }
}
