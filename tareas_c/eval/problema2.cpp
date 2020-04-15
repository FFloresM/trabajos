#include <stdio.h>

int main()
{
	int genero[60];
	int edad[60];
	int gente;
	do{
		printf("Ingrese cantidad de espectadores\n");
		scanf("%d", &gente);
	}while(gente<1 || gente>60);

	printf("Ingrese edad y género (separados por espacio)\n");
	for (int i = 0; i < gente; ++i)
	{
		scanf("%d %d", &edad[i], &genero[i]);
	}
	int max = 0;
	int count= 0;
	for (int i = 0; i < gente; ++i)
	{
		if (genero[i] == 2)
		{
			if (edad[i] > max)
			{
				max = edad[i];
			}
		}
		else{
			if (edad[i] < 15)
			{
				count++;
			}
		}
	}
	printf("El hombre más viejo tiene %d años\n", max);
	printf("La cantidad de mujeres con edad menor a 15 es %d\n", count);

	return 0;
}