#include <stdio.h>
#include "prueba.h"

struct Nodo
{
	struct p persona;
	struct Nodo* sig;
};

struct Nodo *crear_lista();
void agregar_elemento_lista(struct Nodo** lista, struct p persona);
void remover_elemento_lista(struct Nodo** lista, struct p persona);

