#include "lista.h"

int crear_lista(void value){
	Nodo * head = NULL;
	head = (Nodo*) malloc(sizeof(Nodo));
	if (head==NULL)
	{
		return 1
	}
	head->value = value;
	head->sig = NULL;
}

void agragar_elemento_lista(struct Nodo* Lista, void value){
	struct Nodo* new_nodo = (struct Node*)malloc(sizeof(struct Node));
	new_nodo->value = value;
	new_nodo->sig = NULL;
	Lista->sig = new_nodo;
}

void remover_elemento_lista(struct Node* Lista,void value){
	struct Node* temp = Lista;
	while(temp!=NULL){
		if(temp->value == value)
			free(temp); //repare this
		temp=temp->sig;
	}

}