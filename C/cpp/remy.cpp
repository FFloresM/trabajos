#include <iostream>
#include <vector>
using namespace std;

class Ratoncito
{
private:
	string nombre;
	int edad;
	int peso;
public:
	Ratoncito(string nombre, int edad, int peso){
		this->nombre=nombre;
		this->edad=edad;
		this->peso=peso;
	}

	string getNombre(){return this->nombre;}
	int getEdad(){return this->edad;}
	int getPeso(){return this->peso;}

	void setNombre(string nombre){this->nombre=nombre;}
	void setEdad(int edad){this->edad=edad;}
	void setPeso(int peso){this->peso=peso;}

	
};

class Comensal: public Ratoncito
{
private:
	int presupuesto;
public:
	Comensal(string nombre, int edad, int peso, int presupuesto):Ratoncito(nombre, edad, peso){
		this->presupuesto=presupuesto;
	}

	int getPresupuesto(){return this->presupuesto;}
	void setPresupuesto(int pres){this->presupuesto=pres;}
	
};

class Trabajador: public Ratoncito
{
private:
	int salario;
public:
	Trabajador(string nombre, int edad, int peso, int salario):Ratoncito(nombre, edad, peso){
		this->salario=salario;
	}

	int getSalario(){return this->salario;}
	void setSalario(int sal){this->salario=sal;}
	
};

class Restaurant
{
private:
	string fecha;
	int maxTrabajador = 3;
	int maxComensal = 6;
	int pesoMax = 300;
	vector<Trabajador*> trabajadores;
	vector<Comensal*> comensales;
	
public:
	Restaurant(string fecha){
		this->fecha=fecha;
	}

	string getFecha(){return this->fecha;}
	void setFecha(string fecha){this->fecha=fecha;}

	void agregarTrabajador(Trabajador *rata){
		if(this->trabajadores.size()<=this->maxTrabajador)
			this->trabajadores.push_back(rata);
		else
			cout << "no caben más trabajadores"<<endl;
	}

	void agregarComensal(Comensal *rata){
		if(this->comensales.size()<=this->maxComensal)
			this->comensales.push_back(rata);
		else
			cout << "no caben más comensales"<<endl;
	}

	void Estable(){
		int suma=0;
		for (int i = 0; i < this->trabajadores.size(); i++){
			suma+=this->trabajadores[i]->getPeso();
		}
		for (int i = 0; i < this->comensales.size(); i++){
			suma+=this->comensales[i]->getPeso();
		}
		if(suma>this->pesoMax)
			cout<<"El restaurante CLAPSARÁ!!!"<<endl;
		else
			cout << "El peso total de ratas es menor al maximo permitido. Estamos seguros :D"<<endl;
	}

	void ganancia(){
		int ganancia=0,perdida=0;
		for (int i = 0; i < this->trabajadores.size(); i++)
		{
			perdida += this->trabajadores[i]->getSalario();
		}
		for (int i = 0; i < this->comensales.size(); i++)
		{
			ganancia += this->comensales[i]->getPresupuesto();
		}
		if(ganancia>perdida)
			cout << "Hoy obtuvimos ganancias B')"<<endl;
		else
			cout<< "Hoy tuvimos pérdidas. Nos fuimos a la B :'("<<endl;
	}
};

int main()
{
	Trabajador *T1 = new Trabajador("pepo", 10, 15, 1500);
	Trabajador *T2 = new Trabajador("pepe", 12, 17, 1500);
	Trabajador *T3 = new Trabajador("pepa", 14, 20, 1500);

	Comensal *C1 = new Comensal("José Manuel", 20, 40, 1000);
	Comensal *C2 = new Comensal("Roberto Andrés", 22, 45, 1500);
	Comensal *C3 = new Comensal("María Ignacia", 25, 60, 1000);

	cout << "Bienvenido al restaurant de Remy"<<endl;
	string f;
	cout << "ingrese fecha d/m/a: ";
	cin >> f;
	Restaurant *ElRestaurantDeRemy = new Restaurant(f);
	cout << "El día de hoy "<<ElRestaurantDeRemy->getFecha()<<":"<<endl;

	ElRestaurantDeRemy->agregarTrabajador(T1);
	ElRestaurantDeRemy->agregarTrabajador(T2);
	ElRestaurantDeRemy->agregarTrabajador(T3);

	ElRestaurantDeRemy->agregarComensal(C1);
	ElRestaurantDeRemy->agregarComensal(C2);
	ElRestaurantDeRemy->agregarComensal(C3);

	ElRestaurantDeRemy->Estable();
	ElRestaurantDeRemy->ganancia();
	return 0;
}