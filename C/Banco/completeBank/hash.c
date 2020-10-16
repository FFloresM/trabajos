// https://twpower.github.io/160-hash-table-implementation-in-cpp-en

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "lista.h"

int my_str_cmp(const char * str1, const char * str2) {

	while (*str1 != '\0' && (*str1 == *str2)) {
		str1++;
		str2++;
	}
	return *str1 - *str2;

}

int crear_hash(const char * str) { //Devuelve numero de letra del abecedario

	int num = 0;
  num = str[0] - '0' - 17;
	return num;

}

void agregar_elemento_hash(PERSONA *p) {

	int index = crear_hash(p->apellido);

	// insert if first is NULL
	if (tb[index] == NULL) {
		tb[index] = p;
	}
	// traverse list one by one
	// change duplicated value if not then add it to front

	else {

		PERSONA * cur = tb[index];

		while (cur != NULL) {

			cur = cur->next;
		}

		// add to front if it is not duplicated
		p->next = tb[index];
		tb[index] = p;
	}

  ultimo_id++;

}

void print_hash() {

	for (int i = 0; i < MAX_TABLE; ++i) {
		if (tb[i] != NULL) {

			printf("index : %d\n", i);

			PERSONA * cur = tb[i];

			while (cur != NULL) {
				printf("{ %s, %s }, ", cur->nombre, cur->apellido);
				cur = cur->next;
			}
			printf("\n");
		}
	}
}

PERSONA find_hash_by_id(int id){

  	for (int i = 0; i < MAX_TABLE; ++i) {
		if (tb[i] != NULL) {

			PERSONA * cur = tb[i];

			while (cur != NULL) {
				if (cur->id == id){ 
          printf("{ %s, %s }, ", cur->nombre, cur->apellido);
          return *cur;
        }
        cur = cur->next;
			}
		}
	}
  PERSONA *p = NULL;
  return *p;

}

PERSONA *find_hash_by_name(char *name){

  	PERSONA *inicio_lista = crear_lista();

    for (int i = 0; i < MAX_TABLE; ++i) {
		if (tb[i] != NULL) {

			PERSONA * cur = tb[i];

			while (cur != NULL) {
        if (strcmp(cur->nombre, name) == 0){ 
          agregar_elemento_lista(&inicio_lista, cur->id, cur->nombre, cur->apellido,cur->mail, cur->sexo, cur->direccion, cur->saldo); 
        }
        cur = cur->next;
			}
		}
	}
  return inicio_lista;
}

PERSONA *find_hash_by_lastname(char *lastname){

  	PERSONA *inicio_lista = crear_lista();

    for (int i = 0; i < MAX_TABLE; ++i) {
		if (tb[i] != NULL) {

			PERSONA * cur = tb[i];

			while (cur != NULL) {
        if (strcmp(cur->apellido, lastname) == 0){ 
          agregar_elemento_lista(&inicio_lista, cur->id, cur->nombre, cur->apellido,cur->mail, cur->sexo, cur->direccion, cur->saldo); 
        }
        cur = cur->next;
			}
		}
	}
  return inicio_lista;
}


void remover_elemento_hash(int id) {

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

}


