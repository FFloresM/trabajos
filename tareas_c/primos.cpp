#include <iostream>

using namespace std;

int main()
{

	int cont, primo = 0;
	int vect[1000];
	int k;
	cout << "ingrese valor\n";
	cin >> k;

	int i = 0;
	for (int n = 1; n <= k; ++n)
	{
		primo = 1;
		cont = 2;

		while(cont <= n/2 && primo)
		{
			if (n % cont == 0)
			{
				primo = 0;
			}
			cont ++;
		}

		if (primo)
		{
			//cout << n << endl;
			vect[i] = n;
			i++;
		}
	}


for (int p = 0; p < i; ++p)
{
	cout<< "vect["<<p<<"] = " << vect[p] << endl;
}

	return 0;
}