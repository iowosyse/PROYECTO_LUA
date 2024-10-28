#include <stdio.h>
#include "utilidades/myList.h"

int main(void) {
    MyList *lista = crearLista(1, 0);
    insertarOrdenado(lista, 6);
    mostrarLista(lista);
    insertarOrdenado(lista, 9);
    mostrarLista(lista);
    insertarOrdenado(lista, 4);
    mostrarLista(lista);
    insertarOrdenado(lista, 5);
    mostrarLista(lista);
    borrar(lista, 6);
    mostrarLista(lista);

}
