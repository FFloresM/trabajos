struct PERSONA *crear_lista();

void agregar_elemento_lista(struct PERSONA **cabecera, int id, char* nombre, char *apellido, char *mail, char *genero, char* direccion, int saldo);

void remover_elemento_lista(struct PERSONA **head, struct PERSONA *p);

void imprimir_lista(PERSONA *cabecera);

void ordenar_por_saldo(struct PERSONA **lista);

void reverse(struct PERSONA** head);

// https://www.geeksforgeeks.org/insertion-sort-for-singly-linked-list/

// Function to insert a given node in a sorted linked list 
void sortedInsert(struct PERSONA** head_ref, struct PERSONA* new_node);

// function to sort a singly linked list using insertion sort 
void insertionSort(struct PERSONA **head_ref);

