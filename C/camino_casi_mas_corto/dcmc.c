#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int d;
	int w;
	struct node *sig;
}nodo;


void leer_grafo(/*struct *lista[10]*/){
	char nombre[100];
	printf("Nombre Archivo : ");
	scanf("%s", nombre);
	FILE *fp;
	char car[10];
	fp = fopen(nombre, "r");
	if (fp==NULL){
		printf("Error en el archivo.\n");
		exit(1);
	}
 	while (feof(fp) == 0){
 		fgets(car,100,fp);
 		printf("%s",car);
 	 }
 	 printf("\n");   
 	 fclose(fp);
}

nodo *nuevo_nodo(int id, int peso){
	nodo *q = (nodo *)malloc(sizeof(nodo));
	if(!q)
		printf("Error\n");
	q->d = id;
	q->w = peso;
	q->sig = NULL;
	return q;
}

void mostrar_lista(nodo *h){
	nodo *actual = h;
	
	if(h==NULL)
		printf("lista vacia\n");
	else
		while(actual){
			printf("%d\n", actual->d);
			actual = actual->sig;
		}
}

void agregar(nodo *h, int val, int p){
	nodo *actual = h;
	while(actual->sig != NULL){
		actual = actual->sig;
	}
	actual->sig = nuevo_nodo(val, p);
}

int main(int argc, char const *argv[]){

	int n, m;
	int s, d;
	int u, v, p;
	nodo *grafo[20];
	nodo *h, *t;

	while(1){
		scanf("%d %d", &n, &m);
		if (m==0 && n==0)
			break;
		for (int i = 0; i < n; ++i){
			grafo[i] = NULL;
		}
		scanf("%d %d", &s, &d);
		while(m--){
			scanf("%d %d %d", &u, &v, &p);				
				if(grafo[u] == NULL){
					h = nuevo_nodo(v,p);
					grafo[u] = h;	
					printf("nuevo %d -> %d\n", u,v);
				}else{
					agregar(grafo[u],v,p);
				//	printf("final %d -> %d\n", u,v);					
				}
		}

	}

	for (int i = 0; i < n; ++i){
		mostrar_lista(grafo[i]);
	}
	
	return 0;
}