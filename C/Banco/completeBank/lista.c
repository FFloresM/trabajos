#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

struct PERSONA* crear_lista(){
  struct PERSONA *p = NULL;
  return p;
}

void agregar_elemento_lista(struct PERSONA **cabecera, int id, char* nombre, char *apellido, char *mail, char *genero, char* direccion, int saldo){
  PERSONA *p = malloc(sizeof(struct PERSONA));
  p->id = id;
  strcpy(p->nombre, nombre);
  strcpy(p->apellido, apellido);
  strcpy(p->mail, mail);
  strcpy(p->sexo, genero);
  strcpy(p->direccion, direccion);
  p->saldo = saldo;
  p->next = NULL;

  struct PERSONA *last = *cabecera;  
  
  if (*cabecera == NULL) 
  { 
      *cabecera = p; 
      return; 
  } 
    while (last->next != NULL) 
        last = last->next; 
  
    last->next = p; 
    return; 
} 
  


void imprimir_lista(PERSONA *cabecera){
  PERSONA *temp = cabecera;
  while (temp != NULL){
    printf("ID: %d Nombre: %s Apellido: %s Saldo: %d \n", temp->id, temp->nombre, temp->apellido, temp->saldo);
    temp = temp->next;
  }
}


/*https://www.geeksforgeeks.org/insertion-sort-for-singly-linked-list/*/

// Function to insert a given node in a sorted linked list 
void sortedInsert(struct PERSONA** head_ref, struct PERSONA* new_node) 
{ 
    struct PERSONA* current; 
    /* Special case for the head end */
    if (*head_ref == NULL || (*head_ref)->saldo >= new_node->saldo) 
    { 
        new_node->next = *head_ref; 
        *head_ref = new_node; 
    } 
    else
    { 
        /* Locate the node before the point of insertion */
        current = *head_ref; 
        while (current->next!=NULL && 
               current->next->saldo < new_node->saldo) 
        { 
            current = current->next; 
        } 
        new_node->next = current->next; 
        current->next = new_node; 
    } 
}   
// function to sort a singly linked list using insertion sort 
void insertionSort(struct PERSONA **head_ref) 
{ 
    // Initialize sorted linked list 
    struct PERSONA *sorted = NULL; 
  
    // Traverse the given linked list and insert every 
    // node to sorted 
    struct PERSONA *current = *head_ref; 
    while (current != NULL) 
    { 
        // Store next for next iteration 
        struct PERSONA *next = current->next; 
  
        // insert current in sorted linked list 
        sortedInsert(&sorted, current); 
  
        // Update current 
        current = next; 
    } 
  
    // Update head_ref to point to sorted linked list 
    *head_ref = sorted; 
} 

// https://www.geeksforgeeks.org/reverse-sublist-linked-list/

void reverse(struct PERSONA** head) 
{ 
    struct PERSONA* prev = NULL;     
    struct PERSONA* curr = *head; 
  
    while (curr) { 
        struct PERSONA* next = curr->next; 
        curr->next = prev; 
        prev = curr; 
        curr = next; 
    } 
    *head = prev; 
} 


/*
  for (int i = 0; i < MAX_TABLE; ++i) {
		
    if (tb[i] != NULL) {

			PERSONA *cur = tb[i];
      PERSONA *prev_person = NULL;
			while (cur != NULL) {
        if (prev_person == NULL && cur->id == id){ // PRIMER ELEMENTO LISTA
          int index = crear_hash(cur->apellido);
          tb[index] = cur->next;
          free(cur);
          ultimo_id--;

        }
        else if (prev_person != NULL && cur->id == id){ // CUANDO NO ES EL PRIMER ELEMENTO DE LA LISTA
          prev_person->next = cur->next;
          free(cur);
          ultimo_id--;
        }
        else if (prev_person != NULL && cur->id == id && cur->next == NULL){ // CUANDO NO ES EL PRIMER ELEMENTO DE LA LISTA Y HAY UN ELEMENTO EN LA LISTA
          int index = crear_hash(cur->apellido);
          tb[index] = NULL;
          free(cur);
          ultimo_id--;
        }
        prev_person = cur;
        cur = cur->next;
			}
		}
	}

}*/
