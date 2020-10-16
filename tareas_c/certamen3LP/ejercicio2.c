#include <stdio.h>

int main(int argc, char const *argv[])
{
	int notas = 45;
	int N[notas]; //notas
	int i,suma=0, promedio;
	printf("Ingrese notas:\n");
	for (i = 0; i < notas; i++)
	{
		scanf("%d", &N[i]);
	}

	for (i = 0; i < notas; i++)
	{
		suma += N[i];
	}

	promedio = suma / notas;

	int max=0, min=10;
	for (i = 0; i < notas; i++){
		if (N[i]>max)
		{
			max = N[i];
		}
		if (N[i]<min)
		{
			min = N[i];
		}
	}

	for (i = 0; i < notas; i++){
		printf("%d, ", N[i]);
	}
	printf("La suma es %d\n", suma );
	printf("El promedio es %d\n", promedio);
	printf("La nota menor es  %d\n", min);
	printf("La nota mayor es  %d\n", max);



	return 0;
}