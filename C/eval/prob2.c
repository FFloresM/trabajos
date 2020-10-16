#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int n;
	printf("Ingrese n\n");
	do{
		scanf("%d", &n);
	}while(n<1 && n>20);

	int vector[n];
	int reverse[n];
	for (int i = 0; i < n; ++i)
	{
		vector[i] = 1+rand() % 10;
		reverse[n-(i+1)]=vector[i];
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d", vector[i]);
	}
	printf("\n");
	int flag=0;
	for (int i = 0; i < n; ++i)
	{
		if (vector[i] != reverse[i]){
			flag=1;
		}
	}

	if (flag==1)
	{
		printf("No es capicua\n");
	}else{
		printf("Es capicua\n");
	}

	if (n%2==0)
	{
		printf("Mediana = %f\n", vector[n/2]);
	}else{
		printf("Mediana = %f\n", (vector[(n/2)-1]+vector[n/2])/2);
	}
	return 0;
}