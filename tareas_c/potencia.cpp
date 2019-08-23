#include <iostream>

using namespace std;

long int pot(int m, int n){
	long int res = 1;
	for (int i = 0; i < n; ++i)
	{
		res *=m;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int base, exp;
	cin >> base;
	cin >> exp;

	cout << "la potencia es " << pot(base,exp)<<endl;
	return 0;
}