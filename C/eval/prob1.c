#include <stdio.h>

float VV(float h, float a, float l){
	return h*(5*a*l)/2;
}

float AA(float h, float a, float l){
	return (5*l*a) + 5*l*h;
}

int main(int argc, char const *argv[])
{
	float h, l, a;
	printf("ingrese h ");
	scanf("%f", &h);
	printf("ingrese l ");
	scanf("%f", &l);
	printf("ingrese a ");
	scanf("%f", &a);

	printf("Volumen del prisma %f\n", VV(h,a,l));
	printf("área del prisma %f\n", AA(h,a,l));
	
	return 0;
}