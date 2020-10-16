#include "pila.h"

int main(int argc, char const *argv[])

{
	struct NodoPila* pila;
	struct NodoPila* temp;
	pila = crear_pila();
	agregar_elemento_pila(&pila, 102, 150000);
	agregar_elemento_pila(&pila, 101, 50000);
	agregar_elemento_pila(&pila, 101, 25000);
	agregar_elemento_pila(&pila, 101, 15000);
	mostrar_pila(pila);
	remover_elemento_pila(&pila);

	printf("==================================\n");
	mostrar_pila(pila);

	return 0;
}