#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Portico
{
	private:
		int precio;
		vector<string> patentes;

	public:
		Portico();

		void CaptarPatente(string patente){
			patentes.append(patente);
		}

		int CalcularPago(string patente){
			int total = count(patentes.begin(), patentes.end(), patente); //cuenta apareiciones de patenten en vector
			return precio*total;
		}

		void ImprimirLista(){
			cout << "Patentes registradas"<<endl;
			for (int i = 0; i < patentes.size(); ++i)
				cout << patentes[i]<< endl;
		}

		void setPrecio(int p){
			precio = p;
		}

	
};

class Autopista: public Portico
{
	private:
		Portico* porticos[10] = {};
	public:
		Autopista();

		void EstablecerPrecios(){
			int precio = 0;
			for (int i = 0; i < 10; ++i)
			{
				cout << "ingrese precio portico "<< i <<": ";
				cin >> precio;
				porticos[i]->setPrecio(precio); 
			}
		}

		int TotalPago(string patente){
			return Portico::CalcularPago(patente);
		}
	
};