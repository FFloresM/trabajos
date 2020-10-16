/*
#include <stdio.h>
#include <stdlib.h>
#include "redes.h"
#include "ordenamiento.h"

int main()
{
  printf("Comienzo de lectura...\n");
  leer_archivo("NSFnet.txt");
  printf("Fin de la lectura...\n");
  printf("Inicio de ordenamiento...\n");
  guardar_nodos_ordenados("out.txt");
  printf("Listo...\n");
  return 0; 
}
*/
#include <stdio.h>
#include "ordenamiento.h"
#include "redes.h"

void print_nodo_info(int n){
  printf("ID\tnum\tlinks\n");
  for(int i = 0; i < n; i++){
    printf("%i\t%i\t%i",nodo[i].id,nodo[i].links,nodo[i].link_ids[0]);
    for(int j = 1; j < nodo[i].links;j++){
      printf("-%i",nodo[i].link_ids[j]);
    }
    printf("\n");
  }
}

void liberar_memoria(){
  for(int i = 0; i < numero_nodos;i++){
    free(nodo[i].link_ids);
  }

  free(nodo);
}

int main(int argc, char** argv){
  leer_archivo(argv[1]);
  print_nodo_info(numero_nodos);
  //bubblesort();
  print_nodo_info(numero_nodos);
  printf("asign: %d \ncomp: %d\n\n",asign, comp);
  guardar_nodos_ordenados("out_bs.txt");
  liberar_memoria();

  leer_archivo(argv[1]);
  print_nodo_info(numero_nodos);
  //mergesort();
  print_nodo_info(numero_nodos);
  printf("asign: %d \ncomp: %d\n\n",asign, comp);
  guardar_nodos_ordenados("out_ms.txt");
  liberar_memoria();

  leer_archivo(argv[1]);
  print_nodo_info(numero_nodos);
  //quicksort();
  print_nodo_info(numero_nodos);
  printf("asign: %d \ncomp: %d\n\n",asign, comp);
  guardar_nodos_ordenados("out_qs.txt");
  liberar_memoria();

  leer_archivo(argv[1]);
  print_nodo_info(numero_nodos);
  //selectionsort();
  print_nodo_info(numero_nodos);
  printf("asign: %d \ncomp: %d\n\n",asign, comp);
  guardar_nodos_ordenados("out_ss.txt");
  liberar_memoria();

  leer_archivo(argv[1]);
  print_nodo_info(numero_nodos);
  //insertionsort();
  print_nodo_info(numero_nodos);
  printf("asign: %d \ncomp: %d\n\n",asign, comp);
  guardar_nodos_ordenados("out_is.txt");
  liberar_memoria();
  return 0;
}
