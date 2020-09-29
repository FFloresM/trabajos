#include "pila.h"
#include <stdlib.h>

struct NodoPila* crear_pila(){
	struct NodoPila *nodoPila = malloc(sizeof(struct NodoPila));
	nodoPila = NULL;
	return nodoPila;
}

void agregar_elemento_pila(struct NodoPila** root, int trsc, int amount){
	struct NodoPila *nodoPila = malloc(sizeof(struct NodoPila));
	if (nodoPila != NULL){
		nodoPila->trsc = trsc;
		nodoPila->amount = amount;
		nodoPila->sig = *root;
		*root = nodoPila;
	}
	
	
}

void remover_elemento_pila(struct NodoPila** root){
	if (!root)
		printf("Error\n");
	struct NodoPila* temp = *root;
	*root = (*root)->sig;
	free(temp);


}

void mostrar_pila(struct NodoPila *top){
	while(top!=NULL){
		printf("%d %d\n", top->trsc, top->amount);
			top = top->sig;
	}
}


