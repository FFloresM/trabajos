#include <stdio.h>
#include <stdlib.h>
#define INF 999999

typedef struct node{
	int d;
	int w;
	struct node *sig;
}nodo;

int del = -1;
int act_dist = -1;


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
	
	if(h == NULL)
		return;
	else
		while(actual){
			printf("%d ", actual->d);
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

void borrar(nodo *p, int v){
	nodo *ant, *nodo_;
	nodo_ = p;
	ant = NULL;
	while(nodo_ && nodo_->d < v){
		ant = nodo_;
		nodo_ = nodo_->sig;
	}
	if (!nodo_ || nodo_->d != v)
		return;
	else{
		if(!ant)
			p = nodo_->sig;
		else
			ant->sig = nodo_->sig;
	}
	free(nodo_);

}

int adyacente(nodo *grafo[], int v, int w){
	/*
	REtorna 1 si v, w son adyacentes y 0 si no.
	*/
	nodo *n = grafo[v];
	while(n){
		//printf("%d\n", n->d);
		if (n->d == w)
			return 1;
		n = n->sig;
	}
	return 0;
}

int peso(nodo *grafo[], int v, int u){
	/*
	devuelve el costo del arco (v,u)
	*/
	nodo *n = grafo[v];
	while(n){
		if(n->d == u)
			return n->w;
		n = n->sig;
	}
	return 0;
}

int minDist(int dist[], int visto[], int n){
	int min = INF, min_i;
	for (int i = 0; i < n; ++i)
		if (visto[i] == 0 && dist[i] <= min)
			min = dist[i], min_i = i; 
	return min_i;	
}

void pathp(int padre[], int j, int n){
	if (padre[j] == -1)
		return;
	pathp(padre, padre[j], n);
	printf("%d ", j);
	if(j!=0 && j!=n && del!=j){
		del = j;
	}
}

void path(int padre[], int j, int n){
	if (padre[j] == -1)
		return;
	path(padre, padre[j], n);
	//printf("%d ", j);
	if(j!=0 && j!=n && del!=j){
		del = j;
	}
}

void solucionp(int dist[], int padre[], int n){
	int s = 0;
	//for (int i = 1; i < n; ++i){
		printf("%d\n%d ", dist[n-1], s);
		pathp(padre,n-1,n-1);
	
		//printf("\neliminar %d",del );
	//}
}

void solucion(int dist[], int padre[], int n){
	int s = 0;
	//for (int i = 1; i < n; ++i){
	//	printf("%d\n%d ", dist[n-1], s);
		path(padre,n-1,n-1);
	
		//printf("\neliminar %d",del );
	//}
}

void dijks_borrar(int actv, nodo *grafo[], int s, int g, int n,int dist[],int padre[]){
	//act_dist = dijkstra(nodo *grafo[], int s, int g, int n);
	while(actv == dijkstra(grafo,dist, padre, s, g, n) ){
		for (int i = 0; i < n; ++i)
			if(adyacente(grafo,i,del))
				borrar(grafo[i],del);
		solucion(dist, padre, n);
	}

	solucionp(dist,padre,n);
}

int dijkstra(nodo *grafo[],int dist[],int padre[], int s, int g, int n){
	//int dist[n];
	//int padre[n];
	int visto[n];

	for (int i = 0; i < n; ++i){
		dist[i] = INF;
		visto[i] = 0;
	}

	dist[s] = 0;
	padre[s] = -1;
//	printf("main dkjt for\n");
	for (int i = 0; i < n-1; ++i){
		int u = minDist(dist, visto, n);

//		printf("minDist\n");
		visto[u] = 1;
//		printf("visto[u]\n");
		for (int j = 0; j < n; ++j){
//			printf("for j\n");
			int ady = adyacente(grafo,u,j);
			int peso_ = peso(grafo,u,j);
		//	printf("%d %d\n", ady, peso_);
			if(!visto[j] && ady && dist[u]+peso_ < dist[j]){
				dist[j] = dist[u] + peso(grafo,u,j);
				padre[j] = u;
//				printf("en if\n");
			}
		}
	}
	//printf("%d\n",dist[g]);
/*	act_dist = dist[n-1];
	solucion(dist, padre, n);
	printf("\n");*/
	return dist[g];
}

int main(int argc, char const *argv[]){

	int n, m;
	int s, d;
	int u, v, p;
	int *a;
	nodo *grafo[20];
	nodo *h, *t;



	while(1){
		scanf("%d %d", &n, &m);
		if (m==0 && n==0)
			break;
		int dist[n], padre[n];
		for (int i = 0; i < n; ++i){
			grafo[i] = NULL;
		}
		scanf("%d %d", &s, &d);
		while(m--){
			scanf("%d %d %d", &u, &v, &p);				
				if(grafo[u] == NULL){
					h = nuevo_nodo(v,p);
					grafo[u] = h;	
				//	printf("nuevo %d -> %d\n", u,v);
				}else{
					agregar(grafo[u],v,p);
				//	printf("final %d -> %d\n", u,v);					
				}
		}
		
		//for (int i = 0; i < n; ++i)
		//	mostrar_lista(grafo[i]);

		act_dist = dijkstra(grafo,dist,padre,s,d,n);
		dijks_borrar(act_dist,grafo,s,d,n,dist,padre);
		printf("\n");
	}
	return 0;
}