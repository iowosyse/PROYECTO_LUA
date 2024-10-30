#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades/myList.h"

void menuListas();
MyList* buscarLista(char nombre[], MyList *listas[]);
void menuInsertar(MyList *lista);

int main(void) {
    int opt;

    do
    {
        printf("--Menu--\n");
        printf("1. Iniciar\n0. Salir\n>> ");
        scanf("%d", &opt);

        switch (opt)
        {
            case 1:
                menuListas();
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("No se vale.\n");
        }
    } while (opt != 0);
}

void menuListas()
{
    MyList *listas[50] = {NULL};
    MyList *listaActual = NULL;
    int opt;

    do
    {
        printf("-------------------\n");
        if (listaActual != NULL)
            printf("--Trabajando con la lista: %s--\n", listaActual->nombre);
        else
            printf("-No hay lista con la que trabajar-\n");

        printf("1. Crear lista\n");
        printf("2. Cambiar lista actual\n");
        printf("3. Insertar elemento\n");
        printf("4. Borrar elemento\n");
        printf("5. Mostrar lista\n");
        printf("0. Volver al menú principal\n>> ");
        scanf("%d", &opt);

        switch (opt)
        {
            case 1:
                int aux, aux1;
                printf("\n 1 = si, 0 = no");
                printf("\nLista circular: ");
                scanf("%d", &aux);
                printf("Lista doble: ");
                scanf("%d", &aux1);

                MyList *nuevaLista = crearLista(aux, aux1);

                int i;
                for (i = 0; i < 50 && listas[i] != NULL; i++) {}
                if (i < 50) {
                    listas[i] = nuevaLista;
                    listaActual = nuevaLista;
                } else {
                    printf("No hay espacio para más listas.\n");
                    free(nuevaLista);
                }
                break;
            case 2:
                char str[30] = {0};
                getchar();
                printf("Cual es el nombre de la lista que quieres usar ahora?\n>>");
                gets(str);
                listaActual = buscarLista(str, listas);
                if (listaActual == NULL) printf("---Esa lista no existe---");
                break;
            case 3:
                if (listaActual == NULL)
                    printf("No hay lista");
                else
                    menuInsertar(listaActual);
                break;
            case 4:
                if (listaActual == NULL)
                    printf("No hay lista");
                else
                {
                    int el;
                    printf("Que elemento quiere eliminar?\n>>");
                    scanf("%d", &el);
                    borrar(listaActual, el);
                }
                break;
            case 5:
                mostrarLista(listaActual);
                break;
            case 0:
                printf("Volviendo al menú principal...\n");
                break;
            default:
                printf("No se vale.\n");
                break;
        }

    } while (opt != 0);
}

void menuInsertar(MyList *lista)
{
    int opt = 0, valor = 0;
    printf("Cual es el elemento a insertar?\n>>");
    scanf("%d", &valor);
    printf("Como lo va a insertar?\n1. Insertar al inicio\n2. Insertar al final\n3. Insertar en orden\n0. Volver\n>>");
    scanf("%d", &opt);

    switch (opt)
    {
        case 1:
            insertarInicio(lista, valor);
            break;
        case 2:
            insertarFinal(lista, valor);
            break;
        case 3:
            insertarOrdenado(lista, valor);
            break;
        case 0:
            printf("Volviendo...");
            break;
        default:
            printf("Opcion invalida");
            break;
    }
}

MyList* buscarLista(char nombre[], MyList *listas[])
{
    MyList *elem = NULL;
    for (int i = 0; i < 50; i++)
    {
        if (listas[i] != NULL && strcmp(listas[i]->nombre, nombre) == 0)
        {
            elem = listas[i];
            break;
        }
    }

    return elem;
}
