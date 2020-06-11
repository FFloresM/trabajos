#include "pila.h"
#include <stdlib.h>

struct NodoPila crear_pila(int t, int a){
	struct NodoPila* nodoPila = (struct NodoPila*)malloc(sizeof(struct NodoPila));
	nodoPila->trsc = t;
	nodoPila->amount = a;
	nodoPila->sig = NULL;
	return nodoPila;
}

void agragar_elemento_pila(struct NodoPila** root, int trsc, int amount){
	struct NodoPila* nodoPila = crear_pila(trsc,amount);
	nodoPila->sig = *root;
}

int remover_elemento_pila(struct NodoPila** root){
	if (!root)
		return -1;
	struct NodoPila* aux = *root;
	*root = (*root)->sig;
	int removido = aux->data;
	free(aux);

	return removido;

}


