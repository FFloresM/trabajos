#include <stdlib.h>
#include <string.h>
#include "lista.h"


struct Nodo *crear_lista(){
	struct Nodo * head = malloc(sizeof(struct Nodo));
	head = NULL;
	return head;
}

void agregar_elemento_lista(struct Nodo** lista, struct Persona persona){
	struct Nodo* nuevo = malloc(sizeof(struct Nodo));
	nuevo->persona = persona;
	nuevo->sig = NULL;

	struct Nodo* actual = *lista;

	if (*lista==NULL){
		*lista = nuevo;
	}

	while(actual->sig!=NULL )
		actual = actual->sig;
	
	actual->sig = nuevo;

}

void remover_elemento_lista(struct Nodo** lista, struct Persona persona){
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

void mostrar_lista(struct Nodo *head){
	while(head!=NULL){
		printf("%d %d\n", head->persona.nombre);
			head = head->sig;
	}
}