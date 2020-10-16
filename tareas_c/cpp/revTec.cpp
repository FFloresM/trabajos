#include <map>
#include <queue>
#include <string>

class Auto {
  private:
     string patente;
     int anno;
     string marca;
 
  public:
   Auto(string patente, int anno, string marca){
      this->patente=patente;
      this->anno=anno;
      this->marca=marca;
   }
  
    void setPatente(string patente) {this->patente = patente;}
    void setAnno (int anno) {this->anno = anno;}
    void setMarca (string marca) {this->marca = marca;}
  
    string getPatente(){return patente;}
    int getAnno(){return anno;}
    string getMarca(){return marca;}
};

class PlantaRev
{
	private:
		queue<map<string, Auto *>> conReserva;
		queue<Auto *> digito_3;
		queue<Auto *> resto;


	public:
		PlantaRev(map<string, Auto* > conReserva){
			this->conReserva.push(conReserva);
		}

		void llegaAuto(Auto * p){
			if(p->patente.back() == "3")
				this->digito_3.push(p);
			else
				this->resto.push(p);
		}

		Auto* atiendeAutoconReserva(){
			if(!this->conReserva.empty()){
				map<string, Auto *> m = this->conReserva.front();
				this->conReserva.pop();
				std::map<string,Auto *>::iterator it=m.begin();
				Auto* a = it->second;
				return a;
			}
			return NULL;
			
		}

		Auto* atiendeAutoconDigito(){
			if(!this->digito_3.empty())
				return this->digito_3.pop();
			return NULL;
		}

		Auto* atiendeResto(){
			if(!this->resto.empty())
				return this->resto.pop();
			return NULL;
		}
	
	
};