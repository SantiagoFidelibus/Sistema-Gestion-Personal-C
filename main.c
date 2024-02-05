#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "Listas.h"
#include "Arreglo.h"
#include "Fila.h"
#include "Arbol.h"
#include "StructsGlobales.h"

///Prototipado:
void verificarInfoEmpleado(int rango, int id, char nombre[]);
void crearArchivo(char archivo[]);
stDatosArchivo cargaStruct();
stDatosArchivo cargarDatosEmpleado();
void cargaEmpleadoArchivo(char archivo[], int dimension);
int cargarArreglo(celda adlEmpleado[], int dimension, char archivo[]);
void pasarDeADLToArchivos(celda adlEmpleado[], int validos);
void deListaAArchivo(nodoEmpleado* lista, int cargo, FILE *archi);
void mostrarRegistrosArchivo(char nombreArchivo[], char rango[]);
void modificar_empleado(int rango);
void eliminarEmpleado(int rango);
void pasarDeArchivoToArbol(nodoArbol* arbol);

int main()
{
    celda adlEmpleado[20];
    int rango = 0;
    printf("\n========================================\n");
    printf(" BIENVENIDO A LA INTERFAZ DE LA EMPRESA");
    printf("\n========================================\n");
    sleep(2);
    system("cls");

    ///----------------------///
    char archivo[] = "Base_De_Datos.bin";
    crearArchivo(archivo);
    ///----------------------///

    int opcion;
    int validos;
    char menu = 's';

    Fila filaEmpleados;
    inicFila(&filaEmpleados);
    nodoArbol* arbol = inicArbol();

    while(menu == 's' || menu == 'S')
    {
        printf("\n");
        printf("****************************************\n");
        printf("*            MENU PRINCIPAL            *\n");
        printf("****************************************\n");
        printf("*                                      *\n");
        printf("*   1. Ingresar Empleado               *\n");
        printf("*   2. Ver Empleados                   *\n");
        printf("*   3. Modificar Empleado              *\n");
        printf("*   4. Eliminar Empleado               *\n");
        printf("*   5. Jerarquia de la Empresa         *\n");
        printf("*   6. Salir                           *\n");
        printf("*                                      *\n");
        printf("****************************************\n");
        printf("\n");

        fflush(stdin);
        if (scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 6)
        {
            system("cls");
            printf("Opcion invalida. Intentalo de nuevo.\n");
            sleep(2);
            system("cls");
            fila_para_cargar();
            system("cls");
            continue;
        }

        system("cls");

        char caso='s';

        switch(opcion)
        {
        case 1:

            cargaEmpleadoArchivo(archivo, 20);

            validos = cargarArreglo(adlEmpleado, 20, archivo);

            pasarDeADLToArchivos(adlEmpleado, validos);

            printf("Presiona 's' para ir al menu: ");
            fflush(stdin);
            scanf("%c", &menu);

            system("cls");
            break;
        case 2:
            while(caso=='s' || caso == 'S')
            {
                system("cls");
                printf("\n------------------------------\n");
                printf("        Ver Empleados\n");
                printf("------------------------------\n");

                printf("\nQue Posicion Jerarquica desea visualizar?\n");
                printf("1. Jefe\n");
                printf("2. Encargado\n");
                printf("3. Empleado\n");
                fflush(stdin);
                if (scanf("%d", &rango) != 1 || rango < 1 || rango > 3)
                {
                    system("cls");
                    fila_para_cargar();
                    system("cls");
                    printf("Opcion invalida. Intentalo de nuevo.\n");
                    sleep(2);
                    system("cls");
                    continue;
                }
                else
                {
                    system("cls");
                    fila_para_cargar();
                    system("cls");
                    if(rango == 1) mostrarRegistrosArchivo("Archivo_1.bin", "Jefes");

                    if(rango == 2)  mostrarRegistrosArchivo("Archivo_2.bin", "Encargados");

                    if(rango == 3) mostrarRegistrosArchivo("Archivo_3.bin", "Empleados");
                }

                printf("Si deseas cambiar de Posicion Jerarquica ingresa 's': ");
                fflush(stdin);
                scanf("%c", &caso);
            }
            system("cls");
            break;
        case 3:
            while(caso=='s' || caso == 'S')
            {
                printf("\n------------------------------\n");
                printf("     Modificar Informacion\n");
                printf("------------------------------\n");
                printf("\nIngresar Rango a buscar: ");
                fflush(stdin);
                scanf("%d",&rango);

                modificar_empleado(rango);

                printf("Si desea modificar otro empleado presione 's': ");
                fflush(stdin);
                scanf("%c", &caso);
            }
            system("cls");
            break;
        case 4:
            while(caso=='s' || caso == 'S')
            {
                printf("\n------------------------------\n");
                printf("       Eliminar Empleado\n");
                printf("------------------------------\n");

                printf("\nIngresar Rango a buscar: ");
                fflush(stdin);
                scanf("%d",&rango);

                eliminarEmpleado(rango);

                printf("Si desea eliminar otro empleado presione 's': ");
                fflush(stdin);
                scanf("%c", &caso);
            }
            system("cls");
            break;
         case 5:
          while(caso=='s' || caso == 'S')
                {
                    printf("\n---------------------------------\n");
                    printf(" Datos Ordenados Jerarquicamente\n");
                    printf("---------------------------------\n");

                    pasarDeArchivoToArbol(arbol);
                    printf("\n\nDesea seguir viendo el Arbol de jerarquia? (s/n)");
                    fflush(stdin);
                    scanf("%c", &caso);
                }
                system("cls");
            break;
        case 6:
            system("cls");
            printf(" Hasta luego!\n");
            return 0;
            break;
        default:
            system("cls");
            printf("Opcion invalida. Intentalo de nuevo.\n");
            sleep(2);
            system("cls");
            break;
        }
    }

    printf("El programa dejara de ejecutarse!");
    sleep(2);

    return 0;
}

///VERIFICAR LA INFORMACION DEL EMPLEADO
void verificarInfoEmpleado(int rango, int id, char nombre[])
{
    FILE *archi;

    if (rango == 1)
    {
        archi = fopen("Archivo_1.bin", "r+b");
    }
    else if (rango == 2)
    {
        archi = fopen("Archivo_2.bin", "r+b");
    }
    else if (rango == 3)
    {
        archi = fopen("Archivo_3.bin", "r+b");
    }

    if (archi == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }

    stDatosArchivo a;

    while (fread(&a, sizeof(stDatosArchivo), 1, archi))
    {
        if (strcmp(a.nombreYApellido, nombre) == 0 && a.codigoDeEmpleado == id)
        {
            return;
        }
    }

    fclose(archi);
}

///VALIDACIONES
int validarDato(const char *dato)
{
    int i = 0;

    while (dato[i])
    {
        if (!isalpha(dato[i]) && !isspace(dato[i]))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int validarNumero(int numero)
{
    return (numero > 0);
}

///OPCION 1
void crearArchivo(char archivo[])
{

    FILE *archi = fopen(archivo, "wb");

    fclose(archi);
}

stDatosArchivo cargaStruct()
{
    stDatosArchivo a;

    printf("\n------------------------------\n");
    printf("      Ingresar Empleado\n");
    printf("------------------------------\n");

    printf("\nIngrese el cargo al que pertenece el empleado:\n");
    printf("1. Jefe\n");
    printf("2. Encargado\n");
    printf("3. Empleado\n");
    fflush(stdin);
    scanf("%d", &a.cargo);
    if(a.cargo < 1 || a.cargo > 3)
    {
        printf("\nTiene que ingresar un numero del 1 al 3");
        sleep(2);
        system("cls");
        return cargaStruct();
    }

    do
    {
        printf("\nIngrese Nombre y Apellido: ");
        fflush(stdin);
        gets(a.nombreYApellido);

        if (!validarDato(a.nombreYApellido))
        {
            printf("\nSolo se pueden ingresar palabras.\n");
            continue;
        }
    }
    while (!validarDato(a.nombreYApellido));

    do
    {
        printf("\nIngrese codigo asociado al Empleado:");
        fflush(stdin);
        if(scanf("%i", &a.codigoDeEmpleado) != 1 || !validarNumero(a.codigoDeEmpleado))
        {
            printf("\nIngrese solo valores numericos\n");
            continue;
        }
        break;
    }
    while(1);

    do
    {
        printf("\nIngrese el sector en el que el Empleado trabaja:");
        fflush(stdin);
        gets(a.sectorAsociado);

        if (!validarDato(a.sectorAsociado))
        {
            printf("\nSolo se pueden ingresar palabras.\n");
            continue;
        }
    }
    while (!validarDato(a.sectorAsociado));

    do
    {
        printf("\nIngrese el Telefono del empleado: ");
        fflush(stdin);
        if(scanf("%i", &a.telefono) != 1 || !validarNumero(a.telefono))
        {
            printf("\nIngrese solo valores numericos\n");
            continue;
        }
        break;
    }
    while(1);

    do
    {
        printf("\nIngrese el DNI del empleado: ");
        fflush(stdin);
        if(scanf("%i", &a.DNI) != 1 || !validarNumero(a.DNI))
        {
            printf("\nIngrese solo valores numericos\n");
            continue;
        }
        break;
    }
    while(1);


    return a;
}

stDatosArchivo cargarDatosEmpleado()
{
    stDatosArchivo a;

    do
    {
        printf("\nIngrese Nombre y Apellido: ");
        fflush(stdin);
        gets(a.nombreYApellido);

        if (!validarDato(a.nombreYApellido))
        {
            printf("\nSolo se pueden ingresar palabras.\n");
            continue;
        }
    }
    while (!validarDato(a.nombreYApellido));

    do
    {
        printf("\nIngrese codigo asociado al Empleado:");
        fflush(stdin);
        if(scanf("%i", &a.codigoDeEmpleado) != 1 || !validarNumero(a.codigoDeEmpleado))
        {
            printf("\nIngrese solo valores numericos\n");
            continue;
        }
        break;
    }
    while(1);

    do
    {
        printf("\nIngrese el sector en el que el Empleado trabaja:");
        fflush(stdin);
        gets(a.sectorAsociado);

        if (!validarDato(a.sectorAsociado))
        {
            printf("\nSolo se pueden ingresar palabras.\n");
            continue;
        }
    }
    while (!validarDato(a.sectorAsociado));

    do
    {
        printf("\nIngrese el Telefono del empleado: ");
        fflush(stdin);
        if(scanf("%i", &a.telefono) != 1 || !validarNumero(a.telefono))
        {
            printf("\nIngrese solo valores numericos\n");
            continue;
        }
        break;
    }
    while(1);

    do
    {
        printf("\nIngrese el DNI del empleado: ");
        fflush(stdin);
        if(scanf("%i", &a.DNI) != 1 || !validarNumero(a.DNI))
        {
            printf("\nIngrese solo valores numericos\n");
            continue;
        }
        break;
    }
    while(1);

    return a;
}

void cargaEmpleadoArchivo(char archivo[], int dimension)
{
    int i =0;
    FILE*archi = fopen(archivo, "wb");
    if(archi != NULL)
    {
        stDatosArchivo a;
        char eleccion = 's';

        while(eleccion == 's' || eleccion == 'S' && i < dimension)
        {

            a = cargaStruct();
            i++;

            fwrite(&a, sizeof(stDatosArchivo), 1, archi);

            printf("\nSi quiere ingresar otro empleado presione 's': ");
            fflush(stdin);
            scanf("%c", &eleccion);

            system("cls");
        }
    }
    fclose(archi);
}

int cargarArreglo(celda adlEmpleado[], int dimension, char archivo[])
{
    int validos = 0;
    int cargo = 0;

    stDatosArchivo auxArchivo;
    empleado auxEmpleado;

    FILE* archi = fopen(archivo, "rb");
    if(archi != NULL)
    {
        while(fread(&auxArchivo,sizeof(stDatosArchivo),1,archi)>0)
        {
            auxEmpleado.codigoDeEmpleado = auxArchivo.codigoDeEmpleado;
            auxEmpleado.DNI = auxArchivo.DNI;
            auxEmpleado.telefono = auxArchivo.telefono;
            strcpy(auxEmpleado.nombreYApellido, auxArchivo.nombreYApellido);
            strcpy(auxEmpleado.sectorAsociado, auxArchivo.sectorAsociado);
            cargo = auxArchivo.cargo;

            validos = alta(adlEmpleado, validos, auxEmpleado, cargo);
        }
    }
    fclose(archi);
    return validos;
}

void pasarDeADLToArchivos(celda adlEmpleado[], int validos)
{
    for (int i = 0; i < validos; i++)
    {
        char nombreArchivo[20];
        sprintf(nombreArchivo, "Archivo_%d.bin", adlEmpleado[i].cargo);

        FILE *archi = fopen(nombreArchivo, "ab");

        if (archi != NULL)
        {
            deListaAArchivo(adlEmpleado[i].listaDeArreglo, adlEmpleado[i].cargo, archi);
            fclose(archi);
        }
        else
        {
            printf("Error al abrir el archivo %s\n", nombreArchivo);
        }
    }
}

void deListaAArchivo(nodoEmpleado* lista, int cargo, FILE *archi)
{
    if(lista != NULL)
    {
        stDatosArchivo aux;

        aux.cargo = cargo;
        aux.codigoDeEmpleado = lista->dato.codigoDeEmpleado;
        aux.DNI = lista->dato.DNI;
        aux.telefono = lista->dato.telefono;
        strcpy(aux.nombreYApellido, lista->dato.nombreYApellido);
        strcpy(aux.sectorAsociado, lista->dato.sectorAsociado);

        size_t elementosEscritos = fwrite(&aux, sizeof(stDatosArchivo), 1, archi);

        if (elementosEscritos != 1)
        {
            printf("Error al escribir en el archivo.\n");
        }

        deListaAArchivo(lista->siguiente, cargo, archi);
    }
}

///OPCION 2
void mostrarRegistrosArchivo(char nombreArchivo[], char rango[])
{
    FILE *archi = fopen(nombreArchivo, "rb");
    stDatosArchivo aux;
    int flag=0;

    if (archi != NULL)
    {
        printf("\n ----------Archivo de %s----------------\n", rango);
        while (!feof(archi))
        {
            fread(&aux, sizeof(stDatosArchivo), 1, archi);
            if (!feof(archi))
            {
                flag = 1;
                puts("\n---------------------------------------");
                printf("Nombre y Apellido:  |%s|", aux.nombreYApellido);
                printf("\nCodigo de empleado: |%d|", aux.codigoDeEmpleado);
                printf("\nSector asociado:    |%s|", aux.sectorAsociado);
                printf("\nTelefono:           |%d|", aux.telefono);
                printf("\nDocumento:          |%d|", aux.DNI);
                puts("\n---------------------------------------");
            }
        }
        fclose(archi);
    }
    if(flag == 0)
    {
        puts("\n---------------------------------------");
        printf("       No se encuentran datos");
        puts("\n---------------------------------------\n");
    }
}

///OPCION 3
void modificar_empleado(int rango)
{
    char nombreEmpleado[50];
    int id;
    int flag = 0;
    do
    {
        printf("\nIngrese Nombre y Apellido: ");
        fflush(stdin);
        gets(nombreEmpleado);

        if (!validarDato(nombreEmpleado))
        {
            printf("\nSolo se pueden ingresar palabras.\n");
            continue;
        }
    }
    while (!validarDato(nombreEmpleado));

    nombreEmpleado[strcspn(nombreEmpleado, "\n")] = '\0';

    do
    {
        printf("\nIngrese codigo asociado al Empleado:");
        fflush(stdin);
        if(scanf("%i", &id) != 1 || !validarNumero(id))
        {
            printf("\nIngrese solo valores numericos\n");
            continue;
        }
        break;
    }
    while(1);


    FILE *archi;

    if (rango == 1)
    {
        archi = fopen("Archivo_1.bin", "r+b");
        if (archi == NULL)
        {
            printf("Error al abrir el archivo.\n");
            return;
        }
        else
        {
            verificarInfoEmpleado(rango, id, nombreEmpleado);
        }
    }
    else if (rango == 2)
    {
        archi = fopen("Archivo_2.bin", "r+b");
        if (archi == NULL)
        {
            printf("Error al abrir el archivo.\n");
            return;
        }
        else
        {
            verificarInfoEmpleado(rango, id, nombreEmpleado);
        }
    }
    else if (rango == 3)
    {
        archi = fopen("Archivo_3.bin", "r+b");
        if (archi == NULL)
        {
            printf("Error al abrir el archivo.\n");
            return;
        }
        else
        {
            verificarInfoEmpleado(rango, id, nombreEmpleado);
        }
    }

    stDatosArchivo a;

    while (fread(&a, sizeof(stDatosArchivo), 1, archi))
    {
        if (strcmp(a.nombreYApellido, nombreEmpleado) == 0 && a.codigoDeEmpleado == id)
        {
            puts("\n--------------------------------");
            printf("Nombre Y Apellido: %s", a.nombreYApellido);
            printf("\nCodigo de Empleado: %i", a.codigoDeEmpleado);
            printf("\nSector Asociado: %s", a.sectorAsociado);
            printf("\nTelefono del Empleado: %i", a.telefono);
            printf("\nDNI del Empleado: %i", a.DNI);
            puts("\n--------------------------------\n");

            printf("\nIntroduce la nueva informacion:\n");

            a = cargarDatosEmpleado();

            fseek(archi, -sizeof(stDatosArchivo), SEEK_CUR);
            fwrite(&a, sizeof(stDatosArchivo), 1, archi);

            system("cls");
            fila_para_cargar();
            system("cls");

            printf("Informacion del Empleado modificada exitosamente.\n");
            flag = 1;
            break;
        }
    }

    fclose(archi);

    if (flag == 0)
    {
        system("cls");
        fila_para_cargar();
        system("cls");
        printf("No se encontro ningun usuario con las credenciales especificadas.\n");
    }
}

///OPCION 4
void eliminarEmpleado(int rango)
{
    char nombreE[50];
    int id;
    char confirmacion;

    FILE *archi;

    if (rango == 1)
    {
        archi = fopen("Archivo_1.bin", "r+b");
        if (archi == NULL)
        {
            printf("Error al abrir el archivo.\n");
            return;
        }
    }
    else if (rango == 2)
    {
        archi = fopen("Archivo_2.bin", "r+b");
        if (archi == NULL)
        {
            printf("Error al abrir el archivo.\n");
            return;
        }
    }
    else if (rango == 3)
    {
        archi = fopen("Archivo_3.bin", "r+b");
        if (archi == NULL)
        {
            printf("Error al abrir el archivo.\n");
            return;
        }
    }
    else
    {
        printf("Rango no valido.\n");
        return;
    }

    printf("\nIngresa el nombre del empleado que deseas eliminar: ");
    fflush(stdin);
    gets(nombreE);

    printf("\nIngresa el codigo del empleado: ");
    fflush(stdin);
    scanf("%d", &id);

    printf("Estas seguro de que deseas eliminar al empleado %s con codigo %d? (s/n): ", nombreE, id);
    fflush(stdin);
    scanf(" %c", &confirmacion);

    if (confirmacion == 's' || confirmacion == 'S')
    {
        stDatosArchivo a;

        FILE *tempArchivo = fopen("temp.bin", "wb");
        if (tempArchivo == NULL)
        {
            printf("Error al abrir el archivo temporal.\n");
            fclose(archi);
            return;
        }

        int encontrado = 0;
        while (fread(&a, sizeof(stDatosArchivo), 1, archi) > 0)
        {
            if (strcmp(a.nombreYApellido, nombreE) == 0 && a.codigoDeEmpleado == id)
            {
                encontrado = 1;
            }
            else
            {
                fwrite(&a, sizeof(stDatosArchivo), 1, tempArchivo);
            }
        }

        fclose(archi);
        fclose(tempArchivo);

        if (encontrado)
        {
            char nombreArchivo[20];
            sprintf(nombreArchivo, "Archivo_%d.bin", rango);

            if (remove(nombreArchivo) == 0)
            {
                rename("temp.bin", nombreArchivo);
                system("cls");
                fila_para_cargar();
                system("cls");
                printf("\nEmpleado eliminado exitosamente.\n");
            }
            else
            {
                printf("Error al eliminar el archivo");
                remove("temp.bin");
            }
        }
        else
        {
            remove("temp.bin");
            printf("No se encontro ningun empleado con el nombre y codigo especificados.\n");
        }
    }
    else
    {
        printf("\nNo se elimino al empleado. Operacion cancelada.\n");
    }
}

///OPCION 5
void pasarDeArchivoToArbol(nodoArbol* arbol)
{
    empleado emp;
    FILE* archi1 = fopen("Archivo_1.bin", "rb");
    FILE* archi2 = fopen("Archivo_2.bin", "rb");
    FILE* archi3 = fopen("Archivo_3.bin", "rb");

    if (archi1 == NULL && archi2 == NULL && archi3 == NULL) {
        printf("Error al abrir los archivos.\n");
        return;
    }

    stDatosArchivo a;

    while (fread(&a, sizeof(stDatosArchivo), 1, archi1)) {
        strcpy(emp.nombreYApellido, a.nombreYApellido);
        arbol = insertarAlArbolEnOrden(arbol, emp);
    }

    printf("\n----- Jefes -----");
    inorden(arbol);

    arbol = inicArbol();

    while (fread(&a, sizeof(stDatosArchivo), 1, archi2)) {

        strcpy(emp.nombreYApellido, a.nombreYApellido);
        arbol = insertarAlArbolEnOrden(arbol, emp);
    }

    printf("\n\n----- Encargados -----");
    inorden(arbol);

    arbol = inicArbol();

    while (fread(&a, sizeof(stDatosArchivo), 1, archi3)) {

        strcpy(emp.nombreYApellido, a.nombreYApellido);
        arbol = insertarAlArbolEnOrden(arbol, emp);
    }

    printf("\n\n----- Empleados -----");
    inorden(arbol);

    fclose(archi1);
    fclose(archi2);
    fclose(archi3);
}
