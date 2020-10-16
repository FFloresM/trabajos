#include <stdio.h>

int main(int argc, char const *argv[])
{
	int alumnos;
	printf("Ingrese cantidad de alumnos:\n");
	scanf("%d", &alumnos);

	int E[alumnos]; //edades de los alumnos
	int i;
	printf("Ingrese edades de los alumnos:\n");
	for (i = 0; i < alumnos; i++)
	{
		scanf("%d", &E[i]);
	}

	for (i = 0; i < alumnos; i++)
	{
		if (E[i] > 15)
		{
			E[i] = -1;
		}
	}

	for (i = 0; i < alumnos; i++)
	{
		if (E[i] != -1)
		{
			printf("%d, ", E[i]);
		}
	}
	printf("\n");
	return 0;
}