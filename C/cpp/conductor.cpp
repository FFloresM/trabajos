//Importar librerías
#include <map> 
#include <vector>
#include <string>
#include <iostream>

using namespace std; // standar namespace para usar cin y cout sin el std::
//clase Kms
class Kms{ 
	private:
		map<string,vector<int>> datos; //mapa de datos: string asociado a un vector de enteros
	
	public:
		//Kms();
		//funcion agregar kms a conductor
		void add_kms(std::string nombre){
			int kms;
			while(cin >> kms) //mientras se lean datos...
				this->datos[nombre].push_back(kms); //... agregarlos al final del vector
		}
		//Función mostrar el mayor
		void mayor(){
			int total = 0;
			int mayor=0;
			string nombre;
			map<string,vector<int>>::iterator it; //iterador para map
			for (it = datos.begin(); it != datos.end(); ++it){
				for (auto& n : it->second) // for para iterar sobre todos los elementos del vector
    					total += n; //se suman en total
				if (total > mayor){
					mayor = total; 
					nombre = it->first; //se guarda el nombre
				}

			}
			cout << nombre <<" "<< total<<endl; //se imprime el nombre y el total del kms
		}

		void menor(){
			int menor = 99999999;
			string nombre;
			map<string,vector<int>>::iterator it; //iterador para map
			for (it = datos.begin(); it != datos.end(); ++it){
				if (it->second.size() < menor){
					menor = it->second.size(); //se guarda el menor
					nombre = it->first; // y el nombre asociado
				}

			}
			cout << nombre <<" "<< menor<<endl;
		
		}
};

int main(int argc, char const *argv[])
{
	Kms *kms = new Kms();
	kms->add_kms("juanito");
	kms->mayor();
	kms->menor();
 	
	return 0;
}