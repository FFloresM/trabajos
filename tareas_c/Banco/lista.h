#include <stdio.h>
#include "pila.h"

struct Persona {
    int id;
    char nombre[50];
    char apellido[50];
    char email[70];
    char genero[20];
    float altura;
    struct NodoPila transacciones;
};

struct Nodo
{
	struct Persona persona;
	struct Nodo* sig;
};


struct Nodo *crear_lista();
void agregar_elemento_lista(struct Nodo** lista, struct Persona persona);
void remover_elemento_lista(struct Nodo** lista, struct Persona persona);
void mostrar_lista(struct Nodo *head);