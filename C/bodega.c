#include <stdio.h>
#include <string.h>

int main()
{
	char *productos[] = {
		"pan", "aceite","sal", "yogur", "jamon",
		"queso", "bebida", "ron", "jalea", "azucar",
		"galleta", "papas fritas", "cereal", "arroz", "limon",
		"leche", "flan", "torta", "pizza", "cafe",
		"te", "lavaloza", "champu", "porotos", "helado"
		};
	//printf("%s\n", productos[3]);

	int estante[5][5] = {
		10,16,24,4,19,
		23,6,5,1,2,
		17,11,3,21,15,
		8,22,7,0,14,
		18,9,12,13,20
	};

	printf("Ingrese producto que desee buscar:\n");
	char item[30];
	scanf("%s", item);
	printf("Buscando %s\n", item);
	int index = -1;
	for (int i = 0; i < 25; i++)
	{
		if (strcmp(item, productos[i]) == 0)
		{
			index = i;
			break;
		}
	}
	if (index == -1)
		printf("Producto no existe\n");
	else
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			if (index == estante[i][j])
			{
				printf("Luegar encontrado: (%d,%d)\n", i,j);
				printf("Pasillo %d, Piso %d\n", i,j);
				break;
			}
		}
	}
	return 0;
}