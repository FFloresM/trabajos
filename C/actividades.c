#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct actividad
{
	char act[50]; 			//Actividad a realizar...
	char hora[10]; 		//Hora en la que se realizara la actividad...
	struct actividad *siguiente; 	//Puntero al siguiente elemento...
};

struct actividad *cabeza = NULL,*cola = NULL;

struct actividad * AnadirActividad(struct actividad *cabeza)
{
   struct actividad *nuevo;

   /*----aquí debería ir la reserva de memoria dinámica para el puntero nuevo
     pero este código no está desarrolado-------*/
   nuevo = (actividad *) malloc(sizeof(actividad));
   /***
	con malloc se reserva memoria dinámica a un puntero, en este caso
	la variable nuevo. En el parentesis anterior a malloc se hace el casting, es decir,
	el tipo de dato para malloc. Se le pasa como parámetro a malloc la cantidad de memoria a reservar, que es
	el tamaño de la estructura activa.
   */

   /*
	malloc se utiliza para reservar memoria dinamica a un puntero.
	En la linea anterior a la variable nuevo (puntero a actividad) se le asigna memoria
	con malloc con un tamaño igual a la estrutura actividad. sizeof retorna el tamaño de la estructura
	para que malloc funcone se debe hacer casting del tipo de dato, en este caso (actividad *)
   */

   printf("Ingrese la Actividad a Registrar : \n");
   scanf("%s",nuevo->act);

   printf("Ingrese la hora de Actividad : \n");
   scanf("%s",nuevo->hora);
   
   nuevo->siguiente = NULL;
  
   if(cola!=NULL)
   {
cola->siguiente = nuevo;
   }
   cola = nuevo;

   if(cabeza==NULL)
   {
     cabeza = nuevo;
   }
   return(cabeza);
}

int main()
{
	int op;

	do{
		system("cls");
		printf("--------------------Agenda Personal--------------------\n");
		printf("1.- Ingresar una actividad\n");
		printf("2.- Revisar la Agenda\n");
		printf("3.- Buscar una actividad\n");
		printf("4.- Eliminar una Actividad\n");
		printf("5.- Terminar\n");


		printf("--------------------Ingrese opción--------------------\n");
		scanf("%d",&op);
		while(op>5 || op<1)
		{
			printf("Ingrese opción entre 1 y 5\n");
			scanf("%d",&op);
		}
		if(op==1)
		{
			cola=AnadirActividad(cabeza);
		}
