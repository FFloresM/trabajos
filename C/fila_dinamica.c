#include <stdio.h>

struct alumno
{
	int rut;
	int temperatura;
	int codigo;
	struct alumno *siguiente;
};

struct alumno lista_alumnos;

void agregar_fila(struct alumno als, int rut, int temperatura, int codigo ){
	struct alumno actual = als;
	while(actual->siguiente != NULL){
		actual = actual->siguiente;
	}

	actual->siguiente = (struct alumno) malloc(sizeof(lista_alumnos));
	actual->rut  = rut;
	actual->temperatura = temperatura;
	actual->codigo = codigo;
}

void sacar_alumno(int rut,struct alumno als){
	struct alumno actual = als;
	struct alumno tmp;
	while(actual->siguiente != NULL){
		if(actual->rut == rut){
			actual = actual->siguiente;
		}
	}
	tmp = actual->siguiente;
	actual->siguiente = tmp->siguiente;
	free(temp);
}

int main()
{
	int rut;
	int temp;
	int codigo;
	scanf("%d", &rut);
	scanf("%d", &temp);
	scanf("%d", &codigo);

	agregar_fila(lista_alumnos, rut, temp, codigo);
	printf("%s\n", "ingrese rut a eliminar");
	scanf("%d", &rut);
	sacar_alumno(lista_alumnos, rut);
	return 0;
}