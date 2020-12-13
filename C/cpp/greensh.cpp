#include <iostream>
#include <queue>
#include <map>
using namespace std;

class Infante{
	private:
		string nombre;
		int edad;
	public:
		Infante(string nombre, int edad){
			this->nombre=nombre;
			this->edad=edad;
		}

		string getNombre(){
			return this->nombre;
		}

		int getEdad(){
			return this->edad;
		}
};

class Regalo{
private:
	string tipo; //madera, metal, magico
	int peso;
	int precio;
public:
	Regalo(string tipo, int precio, int peso){
		this->tipo=tipo;
		this->peso=peso;
		this->precio=precio;
	}

	string getTipo(){
		return this->tipo;
	}

	int getPeso(){
		return this->peso;
	}

	int getPrecio(){
		return this->precio;
	}
};

class myComparison
{
public:
    bool operator() (Infante inf1, Infante inf2)
    {
        return inf1.getEdad() < inf2.getEdad();
    }
};


int main (){
	
	Infante *a1 = new Infante ("George Miller" , 7);
	Infante *a2 = new Infante ("Nancy Martinez" , 12);
	Infante *a3 = new Infante ("William Wilson" , 3);
	Infante *a4 = new Infante ("David Smith" , 4);
	Infante *a5 = new Infante ("Lisa White" , 9);
	Infante *a6 = new Infante ("Paul Thompson" , 5);
	Infante *a7 = new Infante ("Stefano Ardito", 11);
	
	Regalo *r1 = new Regalo ("Madera" , 3000 , 100);
	Regalo *r2 = new Regalo ("Metal" , 5500 , 300);
	Regalo *r3 = new Regalo ("Magico" , 10000 , 5);
	Regalo *r4 = new Regalo ("Magico" , 40500 , 15);
	Regalo *r5 = new Regalo ("Metal" , 6000 , 500);
	Regalo *r6 = new Regalo ("Magico" , 80500 , 3);
	Regalo *r7 = new Regalo ("Cyber Punk", 26000, 70);

	map<Infante*, Regalo*> regalos;
	regalos[a1] = r1;
	regalos[a2] = r2;
	regalos[a3] = r3;
	regalos[a4] = r4;
	regalos[a5] = r5;
	regalos[a6] = r6;
	regalos[a7] = r7;

	map<Infante*, Regalo*>::iterator it=regalos.begin();


	for(it=regalos.begin(); it!=regalos.end(); it++){

		cout << it->first->getNombre() << endl;
	}

	int total = 0;
	for(it=regalos.begin(); it!=regalos.end(); it++){
		
		total+=it->second->getPrecio();
	}
	cout << "dinero recaudado: " << total << endl;


	return 0;
}