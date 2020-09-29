void leer_archivo(char* filename);

int numero_nodos;
int numero_links;

//Para crear el type nodo
typedef struct Nodo {
  int id;
  int *link_ids;
  int links;
} Nodo;

Nodo *nodo;