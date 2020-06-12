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
		 	return nombre + "::" + email + "::" + sexo;	
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
   #include <iostream>
#include <Vector>
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
         return nombre + "::" + email + "::" + sexo;  
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
   
   if (miLista.empty() ) cout << "2.Lista Vacia" << endl;
   else cout << "2.Algo tiene..." << endl;
   
   for (int i=0; i < miLista.size(); i++)
   {
        //cout << i << "==" << miLista[i]->mostrar() << endl;
        cout << i << "::" << miLista.at(i)->mostrar() << endl;
   }
  
   cout << "el email de la posicion 5 es " << miLista.at(5)->getEmail() << endl;
   
   miLista.erase(miLista.begin()+5);
   cout << "el nuevo email de la posicion 5 es " << miLista.at(5)->getEmail() << endl;
 
    
   cout << "el sexo del 1ero es " << miLista.front()->getSexo() << endl;
   cout << "la edad del 1ero es " << miLista.front()->getEdad() << endl << endl;
   
   cout << "el nombre y la edad del ultimo es " << miLista.back()->getNombre() << " " << miLista.back()->getEdad() << endl;
  
   miLista.pop_back();
   
   cout << "el nombre y la edad del ultimo es " << miLista.back()->getNombre() << " " << miLista.back()->getEdad() << endl;
   
   for (int i=0; i < miLista.size(); i++)
   {
        //cout << i << "==" << miLista[i]->mostrar() << endl;
        cout << i << "::" << miLista.at(i)->mostrar() << endl;
   }
   return 0;
}
   if (miLista.empty() ) cout << "2.Lista Vacia" << endl;
   else cout << "2.Algo tiene..." << endl;
   
   for (int i=0; i < miLista.size(); i++)
   {
   	  //cout << i << "==" << miLista[i]->mostrar() << endl;
   	  cout << i << "::" << miLista.at(i)->mostrar() << endl;
   }
  
   cout << "el email de la posicion 5 es " << miLista.at(5)->getEmail() << endl;
   
   miLista.erase(miLista.begin()+5);
   cout << "el nuevo email de la posicion 5 es " << miLista.at(5)->getEmail() << endl;
 
    
   cout << "el sexo del 1ero es " << miLista.front()->getSexo() << endl;
   cout << "la edad del 1ero es " << miLista.front()->getEdad() << endl << endl;
   
   cout << "el nombre y la edad del ultimo es " << miLista.back()->getNombre() << " " << miLista.back()->getEdad() << endl;
  
   miLista.pop_back();
   
   cout << "el nombre y la edad del ultimo es " << miLista.back()->getNombre() << " " << miLista.back()->getEdad() << endl;
   
   for (int i=0; i < miLista.size(); i++)
   {
   	  //cout << i << "==" << miLista[i]->mostrar() << endl;
   	  cout << i << "::" << miLista.at(i)->mostrar() << endl;
   }
   return 0;
}