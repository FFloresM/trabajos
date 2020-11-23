#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> pila;

	for (int i = 1; i <=5 ; ++i)
	{
		pila.push(i);
	}

	cout << pila.top()<< endl;
	pila.push(10);
	cout << pila.top()<< endl;

	

	while(!pila.empty())
		pila.pop();

	if (pila.empty())
	{
		cout << "La pila está vacía\n";
	}
	return 0;
}