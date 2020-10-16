#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "red.h"

void leer_archivo(char* filename){
	FILE *f = fopen(filename, "r");
	char path[50];
	int n_nodes, n_links;
	int source, dest, hops, link_id;
	
	fscanf(f, "Number of nodes: %d\n", &n_nodes);
 	fscanf(f, "Number of links: %d\n", &n_links);
 	Nodo nodes[n_nodes];
 	int links[n_nodes][n_links], aux[n_links];
 	int hops_acum[n_nodes];
 	printf("%d %d\n",n_nodes, n_links );
 	//saltar 3 lineas
 	for (int i = 0; i < 3; ++i)
 		fscanf(f, "%*[^\n]\n"); //lee cualquier cosa hasta \n

 	for (int i = 0; i < n_nodes; ++i){
 		nodes[i].id = i;
 		hops_acum[i] = 0;
 	}
 	char delim[] = "-";
 	int j=0, fuente=0;
 	while(feof(f)==0){
 		fscanf(f,"[%d]\t[%d]\t%d\t%s\n", &source, &dest, &hops, path);
 		hops_acum[source]+=hops;
 		char *ptr = strtok(path,delim);
 		
 		while(ptr!=NULL){
 			int v = atoi(ptr);			
 			if (fuente == source){
 				links[source][j]=v;
 				j++;
 			}else if(fuente!=source){
 				fuente = source;
 				j=0;
 			}
 			ptr = strtok(NULL, delim);
		
			
 		}
 	}


 	for (int i = 0; i < n_nodes; ++i){
 		printf("%d | ", hops_acum[i]);
 		for (int j = 0; j < hops_acum[i]; ++j){
 			printf("%d ", links[i][j]);	
 		}
 		puts("");
 	}
 	

 	printf("%s\n", "hola");

 	fclose(f);
}	


int main(int argc, char const *argv[])
{
	char* file = "NSFnet.txt";
	leer_archivo(file);
	return 0;
}