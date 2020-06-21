#include "lista.h"
#include <stdlib.h>
#include <string.h>

struct Nodo *crear_lista(){
	struct Nodo * head = malloc(sizeof(struct Nodo));
	head = NULL;
	return head;
}

void agragar_elemento_lista(struct Nodo** lista, struct p persona){
	struct Nodo* nuevo = malloc(sizeof(struct Nodo));
	struct Nodo* actual;
	struct Nodo* anterior;

	if (nuevo!=NULL){
		nuevo->persona = persona;
		nuevo->sig = NULL;
	}
	anterior=NULL;
	actual = *lista;

	while(actual!=NULL && strcmp(persona.apellido, actual->persona.apellido)>0){
		anterior = actual;
		actual = actual->sig;
	}

	if (anterior==NULL){
		nuevo->sig = *lista;
		*lista = nuevo;
	}
	else{
		anterior->sig = nuevo;
		nuevo->sig = actual;
	}


}

void remover_elemento_lista(struct Nodo** lista, struct p persona){
	struct Nodo* temp;
	struct Nodo* actual;
	struct Nodo* anterior;

	if (persona.id == (*lista)->persona.id){
		temp = *lista;
		*lista = (*lista)->sig;
		free(temp);
	}
	else{
		anterior = *lista;
		actual = (*lista)->sig;

		while(actual!=NULL && actual->persona.id != persona.id){
			anterior = actual;
			actual = actual->sig;
		}
		if (actual != NULL){
			temp = actual;
			anterior->sig = actual->sig;
			free(temp);
		}
	}

}
