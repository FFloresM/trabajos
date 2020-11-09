#include <iostream>

using namespace std;

int main()
{
	//area del triangualo
	float base, altura;
	cout << "ingrese base\n";
	cin >> base;
	cout << "ingrese altura\n";
	cin >> altura;

	float area = (base*altura)/2;

	cout << "el área del triangulo es: "<<(int)area<<endl;

	//factorial
	int n;
	cout << "ingrse un núnmero\n";
	cin >> n;
	int fact=1;
	for (int i = 2; i <=n ; i++)
	{
		fact *= i; 
	}

	cout << "el factorial de "<<n<<" es "<<fact<<endl;

	return 0;
}