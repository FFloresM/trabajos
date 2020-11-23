#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;
	vector<int> v1(10);
	vector<int> v2(10, 5);

	for(int i=0; i<v2.size(); i++){
		cout << v2[i] << endl;
	}

	if (v.empty())
	{
		cout << "El vector v está vacío\n";
	}

	cout << v2.size() << endl;

	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	v.push_back(100);

	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
	cout << v[10] << endl;
	cout << v.at(10) << endl;

	cout << v.front() << endl;
	cout << v.back() << endl;

	v.pop_back();
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}

	vector<int>::iterator it = v.begin();
	v.insert(it+5, 99);
	//v.insert(5,99);
	cout << endl;
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
	v.erase(it+3);

	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}

	v.clear();

	return 0;
}