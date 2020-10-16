#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash.h"
#include "lista.h"

void cargar_archivo(char * filename) {

  FILE * archivo = fopen(filename, "r"); // Abre el archivo

  if (archivo == NULL) {
    perror("Error al abrir el fichero");
  }

  char cadena[100]; /* Un array lo suficientemente grande como para guardar la línea más larga del fichero */

  int numeroLinea = 0; // Analizo en que linea va el programa

  struct PERSONA *persona_temp; // Persona temporal

  while (fgets(cadena, 100, archivo) != NULL) { //Mientras haya una linea por leer
    
    
    if (numeroLinea >= 1) { //Acá empiezan las personas

      persona_temp = malloc(sizeof(PERSONA)); // Punto Persona Temporal
      
      char * tmp = strtok(cadena, "\t"); //Token (Separaciones)

      persona_temp->id = atoi(tmp); // ID     

      tmp = strtok(NULL, "\t");

      strcpy(persona_temp->nombre, tmp); // Se agrega Nombre

      tmp = strtok(NULL, "\t");
      
      strcpy(persona_temp->apellido, tmp); // Se agregar Apellido

      tmp = strtok(NULL, "\t");
      
      strcpy(persona_temp->mail, tmp); // Se agregar Mail
            
      tmp = strtok(NULL, "\t");
      
      strcpy(persona_temp->sexo, tmp); // Se agregar Genero

      tmp = strtok(NULL, "\t");
      
      strcpy(persona_temp->direccion, tmp); // Se agregar Genero

      persona_temp->next = NULL; //El último

      persona_temp->transacciones = crear_pila(MAX_TRANSACCIONES); // No tiene transacciones

      agregar_elemento_hash(persona_temp); // Se agrega la persona


    }

    numeroLinea++; // Suma una nueva linea para ver en que línea se va

  }

}

void agregar_cliente(int id, char* nombre, char *apellido, char *mail, char *genero, char* direccion){
    
    struct PERSONA *persona_temp; // Persona temporal
    persona_temp = malloc(sizeof(PERSONA)); // Punto Persona Temporal
    
    persona_temp->id = id;  // ID     

    strcpy(persona_temp->nombre, nombre); // Se agrega Nombre
    
    strcpy(persona_temp->apellido, apellido); // Se agregar Apellido
    
    strcpy(persona_temp->mail, mail); // Se agregar Mail
          
    strcpy(persona_temp->sexo, genero); // Se agregar Genero
    
    strcpy(persona_temp->direccion, direccion); // Se agregar Genero

    persona_temp->next = NULL; //El último

    persona_temp->transacciones = crear_pila(MAX_TRANSACCIONES); // No tiene transacciones

    persona_temp->saldo = 0;

    agregar_elemento_hash(persona_temp); // Se agrega la persona

}

void agregar_transaccion(int id, int monto, int tipo){
    for (int i = 0; i < MAX_TABLE; ++i) {
		if (tb[i] != NULL) {

			PERSONA * cur = tb[i];

			while (cur != NULL) {
        if (cur->id == id){ 
            if ((tipo == 101 || tipo == 201) && monto >= 0){
                push(cur->transacciones, monto, tipo);
                if (tipo == 101){
                  cur->saldo = cur->saldo + monto;
                  }
                else{
                  cur->saldo = cur->saldo - monto;
                  }
              }
            else printf("Transacción Inválida\n");
        }
        cur = cur->next;
			}
    } 
  }
}

void deshacer_ultima_transaccion(id){
  for (int i = 0; i < MAX_TABLE; ++i) {
		if (tb[i] != NULL) {

			PERSONA * cur = tb[i];

			while (cur != NULL) {
        if (cur->id == id){ 
          TRANSACCION t = pop(cur->transacciones);
          printf("Se deshizo la transacción del tipo %d con el monto %d en el id %d\n", t.tipo, t.monto, id);
        }
        cur = cur->next;
			}
    } 
  }
}


void generar_lista_ultima_transaccion(int x){
  PERSONA *lista = crear_lista();
  
  for (int i = 0; i < MAX_TABLE; ++i) {
		if (tb[i] != NULL) {

			PERSONA * cur = tb[i];

			while (cur != NULL) {
        if (peek(cur->transacciones).monto >= x && peek(cur->transacciones).tipo == 101){
          //printf("%s", cur->nombre); 
          agregar_elemento_lista(&lista, cur->id, cur->nombre, cur->apellido,cur->mail, cur->sexo, cur->direccion, cur->saldo); 
        }
        cur = cur->next;
			}
		}
	}
  imprimir_lista(lista);
}



void generar_lista_millonarios(){

  PERSONA *lista = crear_lista();
  for (int i = 0; i < MAX_TABLE; ++i) {
		if (tb[i] != NULL) {

			PERSONA * cur = tb[i];

			while (cur != NULL) {
        if (cur->saldo > 0)
        agregar_elemento_lista(&lista, cur->id, cur->nombre, cur->apellido,cur->mail, cur->sexo, cur->direccion, cur->saldo); 
        
        cur = cur->next;
        }
			}
		}
  
  insertionSort(&lista);
  reverse(&lista);
  imprimir_lista(lista);
}


int main(void) {
  

  // VARIABLES A UTILIZAR
  int comando;
  char file[10]; // NOMBRE DEL ARCHIVO  
  char nombre[20],mail[20],genero[20],apellido[20],direccion[20]; //nombres de variables 
  int id,tipo; //variable id 
  int monto;


  printf("\n\nAdministrador de personas. Banco EDA\n==================\n==================\n\n");
  printf("1.- Cargar archivo de clientes\n");
  printf("2.- Agregar cliente\n");
  printf("3.- Eliminar cliente del sistema\n");
  printf("4.- Buscar cliente por RUT, nombre o apellido\n");
  printf("5.- Agregar transaccion\n");
  printf("6.- Deshacer ultima transaccion\n");
  printf("7.- Generar una lista de clientes segun ultima transaccion\n");
  printf("8.- Generar lista con los más adinerados del banco\n");
  printf("9.- Salir\n\n");


  printf("Ingrese comando: \n");
  scanf("%d",&comando);//comando para el usuario

  switch (comando){
    case 1: //Cargar Archivos de clientes    
      printf("Introduce el nombre del archivo para mostrar clientes \n");
      scanf("%s",file);   
      cargar_archivo(file);
      print_hash();
      main();
      break;
    case 2: //opcion para agregar cliente
      printf("Ingrese id\n");
      scanf("%d",&id); 
      printf("Ingrese nombre\n");
      scanf("%s",nombre);
      printf("Ingrese apellido\n");
      scanf("%s",apellido);
      printf("Ingrese mail\n");
      scanf("%s",mail);
      printf("Ingrese direccion\n");
      scanf("%s",direccion);      
      agregar_cliente(id,nombre,apellido,mail,genero,direccion);
      print_hash();
      main();

      break;
    case 3: //opcion para eliminar cliente
      printf("Ingrese id del cliente para eliminar\n");
      scanf("%d",&id);
      remover_elemento_hash(id);
      print_hash();
      main();

      break;
    case 4: //opcion para buscar cliente
      
      printf("Buscar por id, nombre o apellido\nID: 1\nNombre: 2\nApellido: 3\n");
      int selection;
      scanf("%d",&selection);
      if(selection==1){
        printf("id del cliente:\n");
        scanf("%d,",&id);
        PERSONA p = find_hash_by_id(id);
        printf("Nombre: %s Apellido: %s Saldo: %d", p.nombre, p.apellido, p.saldo);
      }
      if(selection==2){
        printf("Nombre:");
        scanf("%s,",nombre);
        PERSONA *p = find_hash_by_name(nombre);
        imprimir_lista(p);

      }
      if(selection==3){
        printf("Apellido:\n");
        scanf("%s,",apellido);
        PERSONA *p = find_hash_by_lastname(apellido);
        imprimir_lista(p);
      }
      
      main();
      
      break;
    case 5: //opcion para agregar transaccion
      printf("Ingrese el tipo de transacción: ");
      scanf("%d",&tipo);
      printf("\nMonto: ");
      scanf("%d",&monto);
      printf("\n ID del cliente: ");
      scanf("%d",&id);
      agregar_transaccion(id,monto,tipo);
      main();

      break;
    case 6: //opcion para borrar la ultima transaccion del cliente asignado
      printf("Ingrese el ID del cliente al cual se le quiere anular la última transacción\n");
      scanf("%d",&id);
      deshacer_ultima_transaccion(id);
      main();

      break;

    case 7:
      printf("Ingrese el monto mínimo en el cual se generará la lista: ");
      scanf("%d",&monto);
      generar_lista_ultima_transaccion(monto);
      main();

      break;
    case 8:
      generar_lista_millonarios();
      main();

      break;
    
  
  }
  return 0; 
}


