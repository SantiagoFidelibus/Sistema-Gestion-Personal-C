#include "Listas.h"

//Lista Simple para el Arreglo De Listas
nodoEmpleado* inicLista()
{
    return NULL;
}

nodoEmpleado* crearNodo(empleado datos)
{
    nodoEmpleado* aux = (nodoEmpleado*) malloc(sizeof(nodoEmpleado));
    aux->dato = datos;
    aux->siguiente = NULL;
    return aux;
}

nodoEmpleado* agregarPpio(nodoEmpleado* lista, nodoEmpleado* nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}

//Lista Doble para Las Filas
nodoDoble* inicListaDoble()
{
    return NULL;
}

nodoDoble* crearNodoDoble(char datos)
{
    nodoDoble* aux = (nodoDoble*) malloc(sizeof(nodoDoble));
    aux->dato = datos;
    aux->ante = NULL;
    aux->sig = NULL;
    return aux;
}

nodoDoble* agregarFinalDoble(nodoDoble* lista, nodoDoble* nuevoNodo)
{
    if (lista == NULL)
    {
        return nuevoNodo;
    }
    else
    {
        nodoDoble *seg = lista;

        while (seg->sig != NULL)
        {
            seg = seg->sig;
        }

        seg->sig = nuevoNodo;
        nuevoNodo->ante = seg;

        return lista;
    }
}

nodoDoble* borrarPrimerNodoDoble(nodoDoble* lista)
{
    if (lista == NULL)
    {
        return NULL;
    }
    else
    {
        nodoDoble *aux = lista;
        lista = lista->sig;
        if (lista)
        {
            lista->ante = NULL;
        }
        free(aux);
        return lista;
    }
}

char verPrimero(nodoDoble* lista)
{
    char rta;

    if(lista)
    {
        rta = lista->dato;
    }
    return rta;
}

void recorrerYmostrarDoble(nodoDoble* lista)
{
     while(lista != NULL)
    {
        escribir(lista);
        lista = lista->sig;
    }
}

void escribir(nodoDoble* aux)
{
        printf("%c", aux->dato);
}
