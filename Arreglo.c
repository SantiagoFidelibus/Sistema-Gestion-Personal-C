#include "Arreglo.h"

int alta(celda adlEmpleado[], int validos, empleado auxEmpleado, int cargo)
{
    nodoEmpleado* aux = crearNodo(auxEmpleado);
    int pos = buscarPosCargo(adlEmpleado, validos, cargo);
    if(pos == -1)
    {
        validos = cargarCargo(adlEmpleado, validos, cargo);
        pos = validos-1;
    }
    adlEmpleado[pos].listaDeArreglo = agregarPpio(adlEmpleado[pos].listaDeArreglo, aux);
    return validos;
}

int buscarPosCargo(celda adlEmpleado[], int validos, int cargo)
{
    int pos = -1;
    int i = 0;

    while(i<validos && pos == -1)
    {
        if(cargo == adlEmpleado[i].cargo)
        {
            pos = i;
        }
        i++;
    }
    return pos;
}

int cargarCargo(celda adlEmpleado[], int validos, int cargo)
{
    adlEmpleado[validos].cargo = cargo;
    adlEmpleado[validos].listaDeArreglo = inicLista();
    validos++;
    return validos;
}
