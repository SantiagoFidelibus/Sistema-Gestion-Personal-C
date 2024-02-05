#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include "Listas.h"
#include "StructsGlobales.h"

typedef struct
{
    nodoDoble* inicio;
    nodoDoble* fin;
}Fila;

//Prototipado
void inicFila(Fila* fila);
void mostrar(Fila* fila);
void agregar(Fila* fila, char dato);
char extraer(Fila* fila);
char primero(Fila* fila);
int filaVacia(Fila* fila);
void fila_para_cargar();

#endif // FILA_H_INCLUDED
