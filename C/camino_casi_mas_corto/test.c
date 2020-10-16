#include <stdio.h>


void print(int j){
	printf("hola mierda\n");
	printf("%d\n", j);
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 3; ++i)
	{
		print(i);
	}
	return 0;
}