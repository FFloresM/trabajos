#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	vector<int> v;
	vector<string> u;
	vector<int> v1(10);
	vector<int> v2(10, 5);

	vector<map<int,string>> vector_de_mapas;
	map<int,string> mimapa, mapa2;
	mimapa[1] = "hola";
	mimapa[2] = "mundo";

	mapa2[10] = "mesa";
	mapa2[34] = "casa";
	vector_de_mapas.push_back(mimapa);
	vector_de_mapas.push_back(mapa2);

	map<int,string>::iterator iter;
	
	for(int i=0; i<vector_de_mapas.size(); i++){
		for ( iter = vector_de_mapas[i].begin(); iter != vector_de_mapas[i].end(); iter++)
		{
			cout << iter -> first << " " << iter -> second<< endl;
		}
		
	}


	for(int i=0; i<v2.size(); i++){
		cout << v2[i] << endl;
	}
	
	if (v.empty())
	{
		cout << "El vector v está vacío\n";
	}
	
	cout<< "el vector v2 tiene " << v2.size() << " elementos" << endl;
	
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
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}

	u.push_back("hola");
	u.push_back("mundo");
	for(int i=0; i<u.size(); i++){
		cout << u[i] << " ";
	}
	return 0;
}