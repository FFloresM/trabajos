#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


struct n{
    char nombre[20];
    int matricula;
    char especialidad[30];
    struct nodo *sig;
}nodo;



nodo *nodo_nuevo(char nombre[20], int matricula, char especialidad[30]){
    nodo *nuevo;
    nuevo=(nodo *)malloc(sizeof(nodo));
    nuevo->nombre = nombre;
    nuevo->matricula = matricula;
    nuevo->especialidad =especialidad;

    if(!nuevo){
        printf("NO se puede reservar memoria dinámica");
        return NULL
    }
    return nuevo;
}

void cambiar(struct nodo *fila){
    nodo *cabeza = fila;
    nodo *tmp = cabeza;
    while(cabeza!=NULL)
        cabeza = cabeza->sig;

    cabeza->sig = tmp->sig;
    free(tmp);
}


int main()
{
    nodo *primero,segundo;
    //lista sin elementos
    primero=NULL; 

    primero = nodo_nuevo("Sebastián", 201156, "Medicina");
    primero->sig = segundo;
    segundo->sig = NULL;

    cambiar(primero);
    return 0;
}
