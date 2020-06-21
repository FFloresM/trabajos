#include "lista.h"

int main(int argc, char const *argv[])
{
	struct p mi_persona = {1,"pancho", "reyes", "pancho@udec.cl", "macho", 1.89};
	struct Nodo* lista;
	lista = crear_lista();
	agregar_elemento_lista(&lista, mi_persona);
	return 0;
}