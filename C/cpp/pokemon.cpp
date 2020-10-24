#include <iostream>
using namespace std;

class Pokemon
{
private:
	string tipo;
	string nombre;
	string apellido;
	int HP;
	string estado;
public:
	Pokemon(string tipo, string nombre, string apellido, int HP, string estado){
		this->tipo = tipo;
		this->nombre = nombre;
		this->apellido = apellido;
		this-> HP = HP;
		this->estado = estado;
	}

	string getTipo() 
	{
		return tipo;
	}	
		string getNombre()
	{ 
		return nombre;
	}	
	string getApellido()
	{ 
		return apellido;
	}
	int getHP()
	{
		return HP ;
	}	
	string getEstado()
	{ 
		return estado;
	}			
	void setNombre(string nombre){
		this->nombre = nombre ;
	}
	void setTipo(string tipo){
		this->tipo = tipo ;
	}
	void setApellido(string apellido){
		this->apellido = apellido ;
	}
	void setHP(int HP){
		this->HP = HP ;
		}
	void setEstado(string estado){
		this->estado = estado;
	}

	void hacerDanio(int danio){
		if (danio > this->HP){
			this->estado = "Fuera de Combate";
			this->HP = 0;
		}else{
			this->HP -= danio;
		}

	}
	
	
};

class PokemonTipo: public Pokemon
{
private:
	string debilA;
public:
	PokemonTipo(string tipo, string nombre, string apellido, int HP, string estado, string debilA):Pokemon(tipo, nombre, apellido, HP, estado){
		this->debilA = debilA;
	}

	void setDebil(string debil){
		this->debilA = debil;
	}
	
};

class Charmander:public PokemonTipo
{
public:
	Charmander(string tipo, string nombre, string apellido, int HP, string estado, string debilA):PokemonTipo(tipo, nombre,apellido,HP,estado,debilA){
		this->setTipo("Fuego");
		this->setNombre("Charmander");
		this->setApellido("Perez");
		this->setDebil("Agua");
	}

	void ataque1(Pokemon *p){
		this->hacerDanio(p->getHP()*1.5);
	}

	void ataque2(Pokemon *p){
		this->hacerDanio(p->getHP()*0.7);
	}

};

class Squirtle:public PokemonTipo
{
public:
	Squirtle(){
		this->setTipo("Agua");
		this->setNombre("Squirtle");
		this->setApellido("Gonzalez");
		this->setDebil("Electrico");
	}

	void ataque1(Pokemon *p){
		this->hacerDanio(p->getHP()*1.5);
	}

	void ataque2(Pokemon *p){
		this->hacerDanio(p->getHP()*0.7);
	}

};

class Pikachu:public PokemonTipo
{
public:
	Pikachu(){
		this->setTipo("Electrico");
		this->setNombre("Pikachu");
		this->setApellido("Flores");
		this->setDebil("Roca");
	}

	void ataque1(Pokemon *p){
		this->hacerDanio(p->getHP()*1.5);
	}

	void ataque2(Pokemon *p){
		this->hacerDanio(p->getHP()*0.7);
	}

};

class Onix:public PokemonTipo
{
public:
	Onix(){
		this->setTipo("Roca");
		this->setNombre("Onix");
		this->setApellido("Pereira");
		this->setDebil("Agua");
	}

	void ataque1(Pokemon *p){
		this->hacerDanio(p->getHP()*1.5);
	}

	void ataque2(Pokemon *p){
		this->hacerDanio(p->getHP()*0.7);
	}

};

class Diglet:public PokemonTipo
{
public:
	Diglet(){
		this->setTipo("Tierra");
		this->setNombre("Diglet");
		this->setApellido("Mellado");
		this->setDebil("Agua");

	}

	void ataque1(Pokemon *p){
		this->hacerDanio(p->getHP()*1.5);
	}

	void ataque2(Pokemon *p){
		this->hacerDanio(p->getHP()*0.7);
	}

};

int main()
{
	Charmander *charmander = new Charmander();
	charmander->setHP(20);

	Squirtle *squirtle = new Squirtle();
	squirtle->setHP(30);

	Diglet *diglet = new Diglet();
	diglet->setHP(50);

	charmander->ataque1(squirtle);
	diglet->ataque1(charmander);
	squirtle->ataque2(diglet);
	return 0;
}


