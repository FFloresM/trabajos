/*
* Implementación de una queue usando dos stacks
*
*/

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int size(stack<int> s1, stack<int> s2){
	return s1.size() + s2.size();
}

bool empty(stack<int> s1, stack<int> s2){
	return s1.empty() && s2.empty();
}

void push(stack<int> &s1, int e){
	s1.push(e);
}

void pop(stack<int> &s1, stack<int> &s2){
	while(!s1.empty()){
		s2.push(s1.top());
		s1.pop();
	}
	s2.pop();
}

int front(stack<int> s1, stack<int> s2){
	while(!s1.empty()){
		s2.push(s1.top());
		s1.pop();
	}
	return s2.top();
}

void clear(stack<int> s1,stack<int> s2){
	//elimina todos los elementos
}


int main()
{
	//cola vacía
	stack<int> s1, s2;

	for (int i = 1; i <=5; ++i)
	{
		push(s1,i);
	}
	
	cout << size(s1,s2) << endl;

	if (empty(s1,s2))
	{
		cout << "Cola está vacía\n";
	}

	pop(s1,s2);
	cout << front(s1,s2) << endl;



	return 0;
}