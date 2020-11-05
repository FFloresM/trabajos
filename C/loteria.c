#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int BuscarGanadorLinea(int carton[][9], int ganadores[]){
	int lista[5];
	int k= 0;
	int suma = 0;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 9; j++)
		{
			if (carton[i][j] != 0)
			{
				lista[k++] = carton[i][j];
			}
		}
		
		for (int l = 0; l < 5; ++l){
			for (int m = 0; m < 5; m++){
				if (lista[l] == ganadores[m]){
					suma++;
				}
			}
			
		}
		k=0;
	}
	if (suma == 5)
		return 1;

	return 0;

}

int main()
{
	srand(time(NULL));

	printf("Numeros ganadores: \n");
	int ganadores[5];
	for (int i = 0; i < 5; i++){
		ganadores[i] = (rand() % 98)+1;
		printf("%d ", ganadores[i]);
	}
	printf("\n");

	printf("Cartón a revisar\n");
	int carton[3][9];
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 9; j++)
		{
			carton[i][j] = 0;
		}
	}

	for (int i = 0; i < 3; i++){	
		for (int j = 0; j < 5; ++j){
			int p = rand() % 8;
			if(carton[i][p] == 0){
				carton[i][p] = (rand() % 98)+1;
			}else{
				j--;
			}
			
		}
	}

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 9; j++)
		{
			printf("%d ", carton[i][j]);
		}
		printf("\n");
	}
	
	if (BuscarGanadorLinea(carton, ganadores)){
		printf("Cartón ganador\n");
	}else
		printf("Carton no gana\n");
	return 0;
}