#include <stdio.h>

float promedio(float arr[], int n){
	float max=0;
	float min=7.0;
	float suma=0;
	int menos=0;
	for (int i = 0; i < n; ++i)
	{
		if(arr[i]>max){
			max = arr[i];
		}
		if (arr[i]<min)
		{
			min=arr[i];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] != max && arr[i] != min)
		{
			suma+=arr[i];
		}
		else{
			menos++;
		}
	}
	
	return suma/(n-menos);

}

int main()
{
	float notas[1000];
	float nota;
	int n;
	printf("Cantidad de notas?\n");
	scanf("%d", &n);
	printf("Ingrese notas\n");
	for (int i = 0; i < n; ++i)
	{
		scanf("%f", &notas[i]);
	}

	printf("El promedio es %.2f\n", promedio(notas,n));


	return 0;
}