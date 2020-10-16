#include <iostream>
using namespace std;

class Personaje{
	protected:
		string nombre;
		string raza;
		int puntos_ataque;
		int puntos_vida;
		string tipo;
	public:
		Personaje(){
			nombre="";
			raza="";
			puntos_ataque=0;
			puntos_vida=0;
			tipo="";
		}
		Personaje(string nombre,string raza,int ap,int hp,string tipo){
			this->nombre=nombre;
			this->raza=raza;
			puntos_vida=hp;
			this->puntos_ataque=ap;
			this->tipo=tipo;
		}
		string getNombre(){
			return nombre;
		}
		string getRaza(){
			return raza;
		}
		int getPA(){
			return puntos_ataque;
		}
		int getPV(){
			return puntos_vida;
		}
		string getTipo(){
			return tipo;
		}
		void setNombre(string nombre){
			this->nombre=nombre;
		}
		void setRaza(string raza){
			this->raza=raza;
		}
		void setPA(int PA){
			puntos_ataque=PA;
		}
		void setPV(int PV){
			this->puntos_vida=PV;
		}
		void setTipo(string tipo){
			this->tipo=tipo;
		}
		virtual void imprimir(){
			cout << "Nombre: " << nombre << ", Raza: " << raza << ", Tipo: " << tipo << ", PV: " << puntos_vida << ", PA: " << puntos_ataque << endl; 
		}
		virtual void atacar(Personaje* P){
			P->setPV(P->getPV()-puntos_ataque);
		}
};

class Paladin: public Personaje{
	int mana;
	public:
		Paladin(string nombre, string raza, int PA, int PV,int mana):Personaje(nombre,raza,PA,PV,"PALADIN"){
			this->mana=mana;
		}
		void imprimir(){
			cout << "Nombre: " << nombre << ", Raza: " << raza << ", Tipo: " << tipo << ", PV: " << puntos_vida << ", PA: " << puntos_ataque << ", Mana: " << mana << endl; 
		}
		void atacar(Personaje* P){
			if (mana >= 20){
				P->setPA(P->getPA()+puntos_ataque);
				mana-=20;
			}
			else{
				P->setPV(P->getPV()-(puntos_ataque/2));
			}
		}
};

class Guerrero: public Personaje{
	public:
		Guerrero(string nombre, string raza, int PA, int PV):Personaje(nombre,raza,PA,PV,"GUERRERO"){
			
		}
		void atacar(Personaje* P){
			if (puntos_vida < 100){
				P->setPV(P->getPV()-(puntos_ataque*2));
			}
			else{
				P->setPV(P->getPV()-puntos_ataque);
			}
		}
};

class Druida: public Personaje{
	int mana;
	public:
		Druida(string nombre, string raza, int PA, int PV,int mana):Personaje(nombre,raza,PA,PV,"DRUIDA"){
			this->mana=mana;
		}
		void imprimir(){
			cout << "Nombre: " << nombre << ", Raza: " << raza << ", Tipo: " << tipo << ", PV: " << puntos_vida << ", PA: " << puntos_ataque << ", Mana: " << mana << endl; 
		}
		void atacar(Personaje* P){
			if (mana > 20){
				puntos_vida+=puntos_ataque*0.2;
				mana-=20;
			}
			P->setPV(P->getPV()-puntos_ataque);
		}
};

int main(){
	Personaje* arr[20] = {};
	string comando = "";
	while(comando != "0"){
		cout << "(1) Crear personaje basico.\n(2) Crear Paladin.\n(3) Crear Guerrero.\n(4) Crear Druida.\n(5) Para imprimir.\n(6) Atacar.\n(0) Para salir del programa\n";
		cin >> comando;
		if (comando == "1"){
			for(int i=0;i<20;i++){
				if(arr[i] == NULL){
					string nombre, raza, tipo;
					int PA,PV;
					cout << "INGRESE NOMBRE, RAZA, TIPO, PUNTOS DE ATAQUE Y PUNTOS DE VIDA: ";
					cin >> nombre >> raza >> tipo >> PA >> PV;
					arr[i] = new Personaje(nombre,raza,PA,PV,tipo);
					break;
				}
			}
		}
		else if (comando == "2"){
			for(int i=0;i<20;i++){
				if(arr[i] == NULL){
					string nombre, raza, tipo;
					int PA,PV,mana;
					cout << "INGRESE NOMBRE, RAZA, PUNTOS DE ATAQUE, PUNTOS DE VIDA Y MANA: ";
					cin >> nombre >> raza >> PA >> PV >> mana;
					arr[i] = new Paladin(nombre,raza,PA,PV,mana);
					break;
				}
			}
		}
		else if (comando == "3"){
			for(int i=0;i<20;i++){
				if(arr[i] == NULL){
					string nombre, raza, tipo;
					int PA,PV;
					cout << "INGRESE NOMBRE, RAZA, PUNTOS DE ATAQUE, PUNTOS DE VIDA: ";
					cin >> nombre >> raza >> PA >> PV;
					arr[i] = new Guerrero(nombre,raza,PA,PV);
					break;
				}
			}
		}
		else if (comando == "4"){
			for(int i=0;i<20;i++){
				if(arr[i] == NULL){
					string nombre, raza, tipo;
					int PA,PV, mana;
					cout << "INGRESE NOMBRE, RAZA, PUNTOS DE ATAQUE, PUNTOS DE VIDA, MAN: ";
					cin >> nombre >> raza >> PA >> PV >> mana;
					arr[i] = new Druida(nombre,raza,PA,PV,mana);
					break;
				}
			}
		}
		else if (comando == "5"){
			for(int i=0;i<20;i++){
				if (arr[i] != NULL){
					arr[i]->imprimir();
				}
			}
		}
		else if (comando == "6"){
			int i1,i2;
			cout << "ESCRIBA LAS DOS POSICIONES DEL PERSONAJE QUE ATACARA AL OTRO: ";
			cin >> i1 >> i2;
			if (arr[i1] != NULL && arr[i2] != NULL){
				arr[i1]->atacar(arr[i2]);
			}
		}
	}
	return 0;
}