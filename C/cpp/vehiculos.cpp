#include <iostream>
using namespace std;

class Vehiculo{
	protected:
		int anodefabricacion, tamanomotor;
		string marca, patente;
	public:
		Vehiculo(string patente, string marca, int ano, int tamano){
			this->anodefabricacion=ano;
			this->tamanomotor=tamano;
			this->patente=patente;
			this->marca=marca;				
		}

		string getMarca(){
			return this->marca;
		}
		
		virtual int Seguro(){
		}
};

class Auto: public Vehiculo{
	private:
		int npuertas;
	public:
		Auto(string patente, string marca, int ano, int tamano, int npuertas):Vehiculo(patente, marca, ano, tamano){
			this->npuertas=npuertas;
		}
		
		int Seguro(){
			return 400000+(100000*(2019-anodefabricacion));
		}
};

class Moto: public Vehiculo{
	private:
		bool enduro;
	public:
		Moto(string patente, string marca, int ano, int tamano, bool enduro):Vehiculo(patente, marca, ano, tamano){
			this->enduro=enduro;
		}
		
		int Seguro(){
			if(enduro){
				return 600000+(100000*(2019-anodefabricacion));
			}
			return 800000+(50000*(2019-anodefabricacion));
		}
};

class cuatroxcuatro: public Vehiculo{
	private:
		int nasientos;
	public:
		cuatroxcuatro(string patente, string marca, int ano, int tamano, int nasientos):Vehiculo(patente, marca, ano, tamano){
			this->nasientos=nasientos;
		}
		
		int Seguro(){
			return 400000+(100000*(2019-anodefabricacion));
		}
};

class Camion: public Vehiculo{
	private:
		int cargamax;
		int tara;
	public:
		Camion(string patente, string marca, int ano, int tamano, float cargamax, float tara):Vehiculo(patente, marca, ano, tamano){
			this->cargamax=cargamax;
			this->tara=tara;
		}
		
		int Seguro(){
			return 500000*(cargamax+tara);
		}
};

int main(){
	int n=5;
	Vehiculo *arr[n]; //nuestro n sera 5
	arr[0]= new Auto("ASDF01","Chevrolet",2018,1600,5);
	arr[1]= new Moto("ASDF02","Suzuki",2015,200,false);
	arr[2]= new Moto("ASDF03","Honda",2016,250,true);
	arr[3]= new cuatroxcuatro("ASDF05","Toyota",2019,3000,5);
	arr[4]= new Camion("ASDF05","",2017,5000,3,3.5);
	int TotalSeguro=0;
	cout << arr[3]->getMarca() << endl;
	for(int i=0;i<n;i++){
		cout << arr[i]->Seguro()<< endl;
	}
	cout<<TotalSeguro;
	return 0;
}