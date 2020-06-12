#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	map<string, int> contagiados;
	std::map<string,int>::iterator it;

	//contagiados["conce"] = 1;
	contagiados["santiago"] = 345;
	contagiados["conce"] += 27;



	std::cout << "mymap contains:\n";
  	for (it=contagiados.begin(); it!=contagiados.end(); ++it)
    	std::cout << it->first << " => " << it->second << '\n';
	return 0;
}