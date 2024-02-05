#include "Fila.h"

void inicFila(Fila* fila)
{
    fila->inicio = inicListaDoble();
    fila->fin = inicListaDoble();
}

void mostrar(Fila* fila)
{
    recorrerYmostrarDoble(fila->inicio);
}

void agregar(Fila* fila, char dato)
{
    nodoDoble* nuevoNodo = crearNodoDoble(dato);

    fila->fin = agregarFinalDoble(fila->fin, nuevoNodo);

    if(fila->inicio == NULL)
    {
        fila->inicio = fila->fin;
    }
    fila->fin = nuevoNodo;
}

char extraer(Fila* fila)
{
    char resp;

    if(fila->inicio != NULL)
    {
        resp = verPrimero(fila->inicio);

        fila->inicio = borrarPrimerNodoDoble(fila->inicio);

        if(fila->inicio == NULL)
        {
            fila->fin = inicListaDoble();
        }
    }
    return resp;
}

char primero(Fila* fila)
{
    char resp;

    if(fila->inicio != NULL)
    {
        resp = verPrimero(fila->inicio);
    }
    return resp;
}

int filaVacia(Fila* fila)
{
    int resp = 0;
    if(fila->inicio == NULL)
    {
        resp = 1;
    }
    return resp;
}

void fila_para_cargar()
{
    Fila filita;
    inicFila(&filita);

    agregar(&filita, 'C');
    agregar(&filita, 'a');
    agregar(&filita, 'r');
    agregar(&filita, 'g');
    agregar(&filita, 'a');
    agregar(&filita, 'n');
    agregar(&filita, 'd');
    agregar(&filita, 'o');
    agregar(&filita, '.');
    agregar(&filita, '.');
    agregar(&filita, '.');

    while(!filaVacia(&filita))
    {
        char elemento = primero(&filita);
        printf("%c", elemento);
        extraer(&filita);
        usleep(100000);
    }
    printf("\n");
    usleep(300000);
}
