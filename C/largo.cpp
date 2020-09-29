#include <iostream>
#include <string>

using namespace std;

int largo(string palabra){
	int suma = 0;
	int i = 0;
	while(palabra[i] != '\0'){
		i++;
		suma+=1;
	}
	return suma;
}

int main(int argc, char const *argv[])
{
	string p = "hola mundo";
	cout << largo(p) << endl;	
	return 0;
}