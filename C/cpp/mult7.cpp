#include <iostream>

using namespace std;

int multiplo_de_siete(int a, int b){
	int count = 0;
	for (int i = a; i <= b; i++){
		if(i%7==0)
			count++;
	}
	return count;
}

int main()
{
	int a,b;
	cout << "ingrese a: ";
	cin >> a;
	cout << "ingrese b: ";
	cin >> b;

	if (b>a){
		cout<<"La cantidad de multiplos de 7 entre "<<a<<" y "<<b<<" es: "<<multiplo_de_siete(a,b)<<endl;
	}else if(a>b)
		cout<<"La cantidad de multiplos de 7 entre "<<a<<" y "<<b<<" es: "<<multiplo_de_siete(b,a)<<endl;
	else
		cout<<"a y b son iguales. Ingrese numeros distintos";
	return 0;
}