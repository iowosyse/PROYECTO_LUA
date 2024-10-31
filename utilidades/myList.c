#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylist.h"

MyList* crearLista(int isCircular, int isDouble) {
    MyList *lista = malloc(sizeof(MyList));
    lista->head = NULL;
    char nom[30] = {0};

    //Si es circular debe ser doble :)
    if (isCircular) {
        lista->isCircular = 1;
        lista->isDouble = 1;
    } else {
        lista->isDouble = isDouble;
    }

    getchar();
    printf("Cual es el nombre de la lista? \n>>");
    gets(nom);

    strcpy(lista->nombre, nom);

    return lista;
}

void insertarInicio(MyList *lista, int valor) {
    Nodo *nodo = malloc(sizeof(Nodo));
    nodo->info = valor;

    if (lista->head == NULL) {
        lista->head = nodo;
        if (lista->isCircular) {
            nodo->sig = nodo;
            nodo->prev = nodo;
        } else {
            nodo->sig = NULL;
            nodo->prev = NULL;
        }
    } else {
        // Conectar el nuevo nodo al inicio de la lista
        nodo->sig = lista->head;

        if (lista->isDouble) {
            nodo->prev = lista->head->prev;
            lista->head->prev = nodo;
        }

        if (lista->isCircular) {
            // En una lista circular, actualizar el último nodo para que apunte al nuevo nodo
            Nodo *ultimo = getLast(lista);
            ultimo->sig = nodo;
            nodo->prev = ultimo;
        }

        // Actualizar el head para que apunte al nuevo nodo
        lista->head = nodo;
    }
    printf("Elemento insertado con exito.\n");
    mostrarLista(lista);
}



void insertarFinal(MyList *lista, int valor) {
    if (lista->head == NULL) {
        insertarInicio(lista, valor);
    } else {
        Nodo *nodo = malloc(sizeof(Nodo));
        nodo->info = valor;
        Nodo *fin = getLast(lista);
        fin->sig = nodo;
        if (lista->isDouble) {
            nodo->prev = fin;
        }
        if (lista->isCircular) {
            nodo->sig = lista->head;
            lista->head->prev = nodo;
        } else {
            nodo->sig = NULL;
        }
    }
    printf("Elemento insertado con exito.\n");
    mostrarLista(lista);
}

void insertarOrdenado(MyList *lista, int valor) {

    if (lista->head == NULL || lista->head->info > valor) {
        insertarInicio(lista, valor);
    } else {
        Nodo *nodo = malloc(sizeof(Nodo));
        nodo->info = valor;
        Nodo *elem = lista->head;
        while (elem->sig != lista->head && elem->sig != NULL && elem->sig->info < nodo->info) {
            elem = elem->sig;
        }
        nodo->sig = elem->sig;
        elem->sig = nodo;
        if (lista->isDouble) {
            nodo->prev = elem;
            if (nodo->sig != NULL) {
                nodo->sig->prev = nodo;
            }
        }
        if (lista->isCircular && nodo->sig == lista->head) {
            lista->head->prev = nodo;
        }
        printf("Elemento insertado con exito.\n");
        mostrarLista(lista);
    }
}

int borrar(MyList *lista, int x) {
    if (lista->head == NULL)
        return -1;

    Nodo *elem = lista->head;
    Nodo *prevElem = NULL;

    do {
        if (elem->info == x) {
            if (prevElem == NULL) {
                lista->head = elem->sig;
                if (lista->isCircular) {
                    getLast(lista)->sig = lista->head;
                }
            } else {
                prevElem->sig = elem->sig;
                if (lista->isDouble && elem->sig != NULL) {
                    elem->sig->prev = prevElem;
                }
            }
            free(elem);
            printf("Elemento eliminado con éxito\n");
            mostrarLista(lista);
            return x;
        }
        prevElem = elem;
        elem = elem->sig;
    } while (elem != lista->head && elem != NULL);

    printf("El elemento que se desea eliminar no existe\n");
    return -1;
}

Nodo* getLast(const MyList *lista) {
    Nodo *fin = lista->head;
    if (fin == NULL) return NULL;

    while (fin->sig != lista->head && fin->sig != NULL) {
        fin = fin->sig;
    }
    return fin;
}

void mostrarLista(const MyList *lista) {
    if (lista->head == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    Nodo *elem = lista->head;
    printf("|");
    do {
        printf("-%d", elem->info);
        elem = elem->sig;
        if (elem == NULL) break;
    } while (elem != lista->head);

    printf("-|\n");
}
