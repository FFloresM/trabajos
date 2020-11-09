#include <iostream>

using namespace std;

int main()
{
	int A[] = {5, 7, 9, 17, 22, 36, 48, 54, 65, 85};
	int B[] = {98, 84, 76, 61, 52, 41, 33, 23, 13, 6};

	int *ptrA = A;
	int *ptrB = B;

	int prod_escalar=0;

	for (int i = 0; i < 10; ++i)
	{
		prod_escalar += (*ptrA)*(*ptrB);
		ptrB++;
		ptrA++;
	}
	cout <<"El producto escalar es: "<<prod_escalar<<endl;

	return 0;
}