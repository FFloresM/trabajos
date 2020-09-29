#include <stdio.h>

//estructutra que representa un nodo del stack
struct NodoPila
{
	int trsc; //codigo transacción
	int amount; //cantidad a retrar o depositar
	struct NodoPila* sig;
};

struct NodoPila* crear_pila();
void agregar_elemento_pila(struct NodoPila** root, int trsc, int amount);
void remover_elemento_pila(struct NodoPila** root);
void mostrar_pila(struct NodoPila *top);