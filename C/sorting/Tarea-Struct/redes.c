#include <stdio.h>
#include <stdlib.h>
#include "redes.h"

void leer_archivo(char* filename)
{
  
  FILE *fp;
  char buff[255];
  
  fp = fopen(filename, "r");
  //Para guardar los datos del input
  fscanf(fp, "Number of nodes: %d\n", &numero_nodos);
  fscanf(fp, "Number of links: %d\n", &numero_links);
  //Para saltarse las lineas de diseño
  fgets(buff, 255, fp);
  fgets(buff, 255, fp);
  fgets(buff, 255, fp);
  //Creación del arreglo de nodos
  nodo = malloc(numero_nodos*sizeof(Nodo));
  //Arreglo que contiene los links de cada nodo
  int links_matrix[numero_nodos][numero_links];

  for(int i = 0; i < numero_nodos; i++){
    nodo[i].id = i;
    //Aca se le entrega la direccion de su arreglo de links correspondientes
    nodo[i].link_ids = links_matrix[i];
    nodo[i].links = 0;
  }

  //Lectura de datos
  int source;
  int dest;
  int hops;
  int link_id;
  for(int i = 0; feof(fp) == 0; i++) {
    fscanf(fp, "[%d]\t[%d]\t%d\t%s\n", &source, &dest, &hops, buff);
    //Solo se leen los que tienen 1 salto
    if(hops > 1){
      continue;
    }else{
      link_id = atoi(buff);
      //printf("[%d]\t[%d]\t%d\t%s\n", source, dest, hops, buff);
      //links_matrix[source][nodo[source].links] = link_id;
      nodo[source].link_ids[nodo[source].links]= link_id;
      nodo[source].links += 1;
    }
  }
  //Fin de la lectura
  
  fclose(fp);
} 