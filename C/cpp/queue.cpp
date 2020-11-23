#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<char> cola;

	cola.push('a');
	cola.push('e');
	cola.push('i');
	cola.push('o');
	cola.push('u');

	for (int i = 0; i < 5; ++i)
	{
		char front = cola.front();
		cout << front << endl;
		cola.pop();
		cola.push(front);
		
	}

	if (cola.empty())
	{
		cout << "cola está vacía\n";
	}

	cout << cola.size() << endl;

	return 0;
}