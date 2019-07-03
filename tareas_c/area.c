#include <stdio.h>
#include <math.h>

int main()
{
	float diam;
	float ancho = 7.4968;
	float diag = 9.1492;

	diam = sqrt(pow(diag,2)-pow(ancho,2));

	printf("%f\n", diam);

	float r = diam/2;


	float area_c = (3.14 * pow(r,2));
	float area_r = (ancho * diam);
	printf("Area circulo %f\n", area_c);
	printf("area Rectangulo %f\n", area_r);
	printf("El área de la zona oscura es %f\n", area_r - area_c);
	return 0;
}