/*
lanzar 24 veces dos dados.
Caballero Méré gana si aparece un 6 en los dos dados, sino, pierde.
Mostrar todos los lanzamientos e imprimir quien gana

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int ganador = 0;
	for (int i = 0; i < 24; ++i)
	{
		
		int dado1 = 1+rand() % 6;
		int dado2 = 1+rand() % 6;
		printf("%d %d\n", dado1, dado2);
		if (dado1==6 && dado1==dado2)
		{
			ganador=1;
		}

	}
	if (ganador==1)
	{
		printf("Ganador Caballero Méré!\n");
	}
	else{
		printf("Pierde Caballero Méré :(\n");
	}
	return 0;
}