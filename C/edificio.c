#include <stdio.h>

struct oficinas
{
	char[10] rut;
	char[30] nombre;
	int telefono;
	int numeroOficina;
	int GastoComunMes;
	int UltimoMesPago;

};


void lista_deudores(int mes, struct oficinas *ed){
	for(int i=0; i< 3*14;i++){
		int acum = 0;
		if (ed[i].UltimoMesPago < mes)
		{
			acum = (mes - ed[i].UltimoMesPago)*ed[i].GastoComunMes;
			printf("deuda acumulada %d, telefono: ", acum, ed[i].telefono);

		}

	}
}

int main()
{
	struct oficinas edificio[3*14];
	int m;
	scanf("%d", &m);

	lista_deudores(m, struct oficinas edificio[3*14];)

	return 0;
}