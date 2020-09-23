#include <iostream>
#include <vector>
using namespace std;

 class Pasajero
 {
 	private:
 		string nombre;
 		int edad;

 	public:
 		Pasajero(string nombre, int edad){
 			this->nombre = nombre;
 			this->edad = edad;
 		}

 		void setNombre(string nombre){this->nombre = nombre;}
 		void setEdad(int edad){this->edad = edad;}

 		string getNombre(){return nombre;}
 		int getEdad(){return edad;}

 };

class Avion
{
private:
	string piloto;
	string modelo;
	int capacidad;
	vector<Pasajero> pasajeros;

public:
	Avion(string piloto, string modelo,	int capacidad){
		this->piloto = piloto;
		this->modelo = modelo;
		this->capacidad = capacidad;
	}
	
	void setPiloto(string piloto){this->piloto = piloto;}
	void setModelo(string modelo){this->modelo = modelo;}
	void setCapacidad(int capacidad){this->capacidad = capacidad;}
	void setPasajeros(vector<Pasajero> psj){this->pasajeros = psj;}

	string getPiloto(){return piloto;}
	string getModelo(){return modelo;}
	int getCapacidad(){return capacidad;}
	vector<Pasajero> getPasajeros(){return pasajeros;}

	int asignarPasajero(Pasajero p){
		if(pasajeros.size()< capacidad){
			pasajeros.push_back(p);
			return pasajeros.size();
		}
		return -1;

	}

	void imprimirListaVuelo(){
		if (pasajeros.size()>0){
		cout << "Asiento N°\t Nombre pasajero\t Edad"<<endl;
			for (int i = 0; i < pasajeros.size(); i++)
			{
				cout<<"\t" << i+1<<"\t"<<pasajeros[i].getNombre()<<"\t\t"<<pasajeros[i].getEdad()<<endl;
			}
		}else cout << "Avión sin pasajeros"<<endl;
	}

	void listaAdultos(){
		for (int i = 0; i < pasajeros.size(); i++){
			if(pasajeros[i].getEdad()>=18){
				cout << pasajeros[i].getNombre()<< endl;
			}
		}
	}

	void vaciarAvion(){
		pasajeros.clear();
	}

	void transferirAvion(Avion *a2){
		if (a2->getPasajeros().size()+getPasajeros().size()<a2->getCapacidad())
		{
			for (int i = 0; i < pasajeros.size(); i++){
				a2->asignarPasajero(pasajeros[i]);
			}
			cout << "Transferencia exitosa!\n";
		}else
			cout << "ERROR: no se puede transferir"<<endl;
	}


};

int main()
{
	Avion *miAvion = new Avion("Juan Papa", "AirBus", 20);
	miAvion->asignarPasajero( Pasajero("Yamilet", 22));
	miAvion->asignarPasajero( Pasajero("El Brayan", 17));
	miAvion->asignarPasajero( Pasajero("Yonatan", 27));
	miAvion->asignarPasajero( Pasajero("Bayron", 18));
	miAvion->asignarPasajero( Pasajero("El Yerson", 15));
	cout << "Lista de pasajeros\n";
	miAvion->imprimirListaVuelo();
	cout << "Lista de pasajeros adultos\n";
	miAvion->listaAdultos();
	miAvion->vaciarAvion();
	miAvion->imprimirListaVuelo();
	miAvion->asignarPasajero( Pasajero("Yamilet", 22));
	miAvion->asignarPasajero( Pasajero("El Brayan", 17));
	miAvion->asignarPasajero( Pasajero("Yonatan", 27));
	miAvion->asignarPasajero( Pasajero("Bayron", 18));
	miAvion->asignarPasajero( Pasajero("El Yerson", 15));
	Avion *nuevo_avion = new Avion("Pedro Pablo", "Boeing 737", 20);
	nuevo_avion->asignarPasajero( Pasajero("Maiga", 30));
	miAvion->transferirAvion(nuevo_avion);
	nuevo_avion->imprimirListaVuelo();
	return 0;
}