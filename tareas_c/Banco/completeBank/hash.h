#include "pila.h"

#define MAX_TABLE 30 // size of table
#define MAX_KEY 20 // include null
#define MAX_TRANSACCIONES 20

typedef struct PERSONA {
	int id;
  char nombre[MAX_KEY];
  char apellido[MAX_KEY];
  char mail[MAX_KEY];
  char sexo[MAX_KEY];
  char direccion[MAX_KEY];
  struct PERSONA *next;
  struct stack *transacciones;
  int saldo;
}PERSONA;

PERSONA * tb[MAX_TABLE]; // hash table

int ultimo_id; // Cantidad de Personas

int my_str_cmp(const char * str1, const char * str2);

int crear_hash(const char * str); //Devuelve numero de letra del abecedari

void agregar_elemento_hash(PERSONA *p);

void print_hash();

PERSONA find_hash_by_id(int id);

void remover_elemento_hash(int id);

PERSONA *find_hash_by_name(char *name);

PERSONA *find_hash_by_lastname(char *lastname);