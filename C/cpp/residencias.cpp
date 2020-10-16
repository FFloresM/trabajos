/*
Dada la pandemia se han establecido varias residencias sanitarias a lo largo del país.

Cada residencia sanitaria tiene capacidad definida para hombres y mujeres.

Al llegar una persona, se le solicita su rut y su sexo ("Masculino" o "Femenino").

Se verifica la disponibilidad de cupo según su sexo y se procede a la admisión. Si no hay
cupo se informa.

Se ha definido una estructura de clases para manejar está situación. Usted sólo deberá
programar los métodos que se indiquen en la clase Residencia.
*/
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Persona
{
	private:
		string rut;
		string sexo;
	public:
		//Constructores
		//set's, get's
		void imprimir();
//asuma que estos métodos ya existen
};

class Residencias
{
	private:
		map<string, vector<Persona *> > lugares;
		map<string, int> cuposHombres;
		map<string, int> cuposMujeres;

	public:
		void agregarResidencia(string nombreResidencia, int cuposH, int cuposM){
			//programar
			if (lugares.find(nombre) == lugares.end()){
				vector<Persona *> lista_personas; //lista vacía
				cuposHombres[nombreResidencia] = cuposH;
				cuposMujeres[nombreResidencia] = cuposM;
				lugares[nombreResidencia] = lista_personas;
				cout <<"Residencia creada\n";
			} else
				cout <<"Residencia ya existe\n";

			
		}

		void agregarPersonaResidencia(string nombreResidencia, string rut, string sexo){
			//programar
			int mujeres=0, hombres=0;
			map<string,int>::iterator it;
			for (it = lugares.begin(); it != lugares.end(); ++it){
				for (int i = 0; i < it->second.size(); ++i){
					if (it->second[i]->getSexo() == "Masculino")
			 			hombres++;
			 		else if(it->second->getSexo() == "Femenino")
			 			mujeres++;
					
				}	
			 }

			Persona * persona = new Persona(rut, sexo); // asumo que así es el constructor de Persona
			if(lugares.find(nombreResidencia) != lugares.end()){ //la residencia existe
				if(sexo == "Femenino" && mujeres < cuposMujeres[nombreResidencia])
					lugares[nombreResidencia].push_back(persona);
				else if(sexo == "Masculino" && hombres < cuposHombres[nombreResidencia])
					lugares[nombreResidencia].push_back(persona);
				else
					cout << "Residencia LLena"<< endl;
				
			}
			
			
		}
		void agregarPersonaResidencia(string nombreResidencia, Persona *p){
			//programar
			int mujeres=0, hombres=0;
			map<string,int>::iterator it;
			for (it = lugares.begin(); it != lugares.end(); ++it){
				for (int i = 0; i < it->second.size(); ++i){
					if (it->second[i]->getSexo() == "Masculino")
			 			hombres++;
			 		else if(it->second->getSexo() == "Femenino")
			 			mujeres++;
					
				}	
			 }
			 if(lugares.find(nombreResidencia) != lugares.end()){ //la residencia existe
			 	if(p->sexo == "Femenino" && mujeres < cuposMujeres[nombreResidencia])
					lugares[nombreResidencia].push_back(p);
				else if(p->sexo == "Masculino" && hombres < cuposHombres[nombreResidencia])
					lugares[nombreResidencia].push_back(p);
				else
					cout << "Residencia LLena"<< endl;
			 }
		}
		void estadisticasHM(){
			//programar
			//muestra cuantos hombres y mujeres hay en total
			//entre todas las residencias sanitarias
			//imprime TOTAL HOMBRES: nnn
			//imprime TOTAL MUJERES: nnn
			int hombres=0, mujeres=0;
			map<string,int>::iterator it;
			for (it = lugares.begin(); it != lugares.end(); ++it){
			 	for (int i = 0; i < it->second.size(); ++i){
					if (it->second[i]->getSexo() == "Masculino")
			 			hombres++;
			 		else if(it->second->getSexo() == "Femenino")
			 			mujeres++;
					
				}	
			 }
			 cout << "TOTAL HOMBRES: "<< hombres<< endl;
			 cout << "TOTAL MUJERES: "<< mujeres<<endl;
		}
}

//De los 4 métodos usted debe escoger 3