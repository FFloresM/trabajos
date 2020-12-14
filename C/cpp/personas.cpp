#include <iostream>
#include <vector>

using namespace std;

class Persona
{
	private:
		string nombre;
		string email;
		int edad;
		char sexo;
	
	public:
		Persona(string nombre, string email, int edad, char sexo){
			this->nombre = nombre;
			this->email = email;
			this->edad = edad;
			this->sexo = sexo;
		}
		
		void setNombre(string nombre){this->nombre = nombre;}
		void setEmail(string email){this->email = email;}
		void setEdad (int edad){this->edad = edad;}
		void setSexo(char c){this->sexo = sexo;}
		
		string getNombre(){return nombre;}
		string getEmail(){return email;}
		int getEdad(){return edad;}
		char getSexo(){return sexo;}
		
		string mostrar(){
		 	return this->nombre + "::" + this->email + "::" + this->sexo;	
		 }
};

int main()
{
   cout << "Contenedores Vector" << endl;
   
   vector<Persona *> miLista;
 
   if ( miLista.empty() ) cout << "1.Lista Vacia" << endl;
   else cout << "1.Algo tiene..." << endl;
     
   Persona *pers = new Persona("Pedro", "pepedro@email.com", 95, 'm');
   
   miLista.push_back(pers);
   
   miLista.push_back(new Persona("Juan", "juan@email.com", 22, 'm'));
   miLista.push_back(new Persona("Maria", "maria@email.com", 45, 'f'));
   miLista.push_back(new Persona("Estela", "este@email.com", 78, 'f'));
   miLista.push_back(new Persona("Jose", "pepe@email.com", 66, 'm'));
   miLista.push_back(new Persona("Luis", "luchin@email.com", 12, 'm'));
   miLista.push_back(new Persona("Ema", "emita@email.com", 51, 'f'));

   for (int i = 0; i < miLista.size(); i++)
   {
      cout << miLista[i]->mostrar() << endl;
   }
   


   return 0;
}