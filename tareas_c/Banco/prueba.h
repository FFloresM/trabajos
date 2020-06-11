#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct p {
    int id;
    char nombre[50];
    char apellido[50];
    char email[70];
    char genero[20];
    float altura;
};

struct p *personas;
int cantidad_de_personas;

void leer_archivo(char* filename);

void ordenar(void);

void imprimir(int posicion);

void imprimir_personas(void);

void swap(struct p *a, struct p *b);
