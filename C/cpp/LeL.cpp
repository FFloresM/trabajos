#include <iostream>
#include <vector>
#include <queue> // std::priority_queue


using namespace std;

class Item{

	private:
		int precio;
		string nombre;
		int danio;
		string tipo_danio;

	public:
		Item(int precio, string nombre, int danio, string tipo_danio){
			this->precio = precio;
			this->nombre = nombre;
			this->danio = dnaio;
			this->tipo_danio = tipo_danio;
		}

	
};

class Tienda{
	private:
		vector<vector<int>> paginas;
	public:
		Tienda();
	
};