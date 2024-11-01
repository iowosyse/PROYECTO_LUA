#ifndef MYLIST_H
#define MYLIST_H

typedef struct Nodo {
    int info;
    struct Nodo *sig;
    struct Nodo *prev;
} Nodo;

typedef struct MyList {
    Nodo *head;
    int isCircular;   // 1 para hacerlo circular. Si es circular fuerza a que la lista sea doble
    int isDouble;// 0 para listas simples, 1 para doblemente enlazadas
    char nombre[30];
} MyList;

MyList* crearLista(int isCircular, int isDouble);
void insertarInicio(MyList *lista, int valor);
void insertarFinal(MyList *lista, int valor);
void insertarOrdenado(MyList *lista, int valor);
int borrar(MyList *lista, int x);
Nodo* getLast(const MyList *lista);
void mostrarLista(const MyList *lista);

#endif

