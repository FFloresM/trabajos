#include <stdio.h>

struct Nodo
{
	void value;
	struct Nodo* sig;
};

void crear_lista(void v);
void agregar_elemento_lista();
void remover_elemento_lista();

