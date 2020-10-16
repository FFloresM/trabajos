#include <stdio.h>

int main(int argc, char const *argv[])
{
	int total = 30;
	int T[total]; //estaturas
	int A[total]; //estatura impar
	int B[total]; //estatura par
	int i,j,k;
	printf("Ingrese las estaturas:\n");
	for (i = 0; i < total; i++)
	{
		scanf("%d", &T[i]);
	}

	j=0,k=0;
	for (int i = 0; i < total; i++)
	{
		if (T[i] % 2 != 0)
		{
			A[j] = T[i];
			j++;
		}else{
			B[k] = T[i];
			k++;
		}
	}
	printf("Estaturas\n");
	for (i = 0; i < total; i++)
	{
		printf("%d, ", T[i]);		
	}
	printf("\n");
	printf("Impares\n");
	for (i = 0; i < j; i++)
	{
		printf("%d, ", A[i]);		
	}
	printf("\n");
	printf("Pares\n");
	for (i = 0; i < k; i++)
	{
		printf("%d, ", B[i]);		
	}
	printf("\n");
	return 0;
}