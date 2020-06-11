#include <stdio.h>

//estructutra que representa un stack
struct NodoPila
{
	int trsc; //deposito o retiro
	int amount; //cantidad a retrar o depositar
	struct NodoPila* sig;
};

struct NodoPila* crear_pila(int t, int a);
void agregar_elemento_pila(struct NodoPila** root, int trsc, int amount);
int remover_elemento_pila(struct NodoPila** root);