#include <stdio.h>
#include <string.h>

int main()
{
	char nombre[30] ; 
	char pass[30] ;

	printf("Ingrese nombre\n");
	scanf("%s", nombre);
	printf("ingrese contraseña\n");
	scanf("%s", pass);

	while( strcmp(nombre,"German") != 0 && strcmp(pass,"2468Ger") !=0){
		printf("Credenciales incorrectas. Intente nuevamente\n");
		printf("Ingrese nombre\n");
		scanf("%s", nombre);
		printf("ingrese contraseña\n");
		scanf("%s", pass);
	}


	printf("Bienvenido\n");
	

	return 0;
}