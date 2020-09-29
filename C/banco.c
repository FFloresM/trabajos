#include <stdio.h>

int main()
{
	printf("Banco CrediFácil\n");
	int M;
	int tipo;
	int t;
	float CT;
	printf("Ingrese monto a solicitar en pesos\n$");
	scanf("%d", &M);
	
	printf("Elija el tipo de crédito\n");
	printf("Tipo 1: 15%% de interés anual\n");
	printf("Tipo 2: 20%% de interés anual\n");
	printf("Tipo 3: 25%% de interés anual\n");
	printf("Tipo 4: 30%% de interés anual\n");
	scanf("%d",&tipo);
	
	printf("Ingrese el número de cuotas\n");
	scanf("%d", &t);
	

	switch (tipo){
		case 1:
			CT = M*1.15*t;
			printf("El costo toal del crédito es %.2f\n", CT);
			break;
		case 2:
			CT = M*1.2*t;
			printf("El costo toal del crédito es %.2f\n", CT);
			break;
		case 3:
			CT = M*1.25*t;
			printf("El costo toal del crédito es %.2f\n", CT);
			break;
		case 4:
			CT = M*1.3*t;
			printf("El costo toal del crédito es %.2f\n", CT);
			break;
		default:
			printf("Opción incorrecta\n");
	}
	
	return 0;
}