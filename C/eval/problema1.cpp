#include <stdio.h>
#include <math.h>

int divisores(int x){
	int i,c=0;
	for ( i = 1; i <= x; i++)
	{
		if((x%i)==0){
			c++;
		}
	}
	return c;
}

int zeta(int m){
	int cont = 0;
	for (int i = 0; i <= m; ++i)
	{
		if (divisores(i) == 2){
			cont++;
		}
	}
	return cont;
}

float sigma(float r, float h){
	float pi = 3.14;
	float area_base = pi*r*r;
	float diag = sqrt( (r*r) + (h*h) );
	float area_total = area_base + (pi*r*diag);
	return area_total;
}

int main()
{
	int v;
	printf("Ingrese un entero mayor a 1\n");
	do{
		scanf("%d", &v);
	}while(v<1);
	printf("Entre 1 y %d hay \n", v);

	printf("%d primos\n", zeta(v));

	printf("Area rombo = %f", sigma(4,3.5)+sigma(4,7));


	return 0;
}