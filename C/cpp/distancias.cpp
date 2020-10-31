#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Distancia{
	private:
		map<string, vector< int > > alternativas;
	public:
		Distancia(){
			
		}
		
	void agregarOrigenDestino(string origenDestino, int km, int velocidad){
		

			
			if (alternativas.find(origenDestino)==alternativas.end())
	  	 	{
			  vector<int> recorrido;
			  recorrido.push_back(km);
			  recorrido.push_back(velocidad);
			  alternativas[origenDestino] = recorrido;
		 	}
			else  
			{
		     alternativas[origenDestino].push_back(km);
		    alternativas[origenDestino].push_back(velocidad);
			}
	}
	
	void imprimir(){
		
		map<string, vector<int> >::iterator b=alternativas.begin();
		  while(b!=alternativas.end())
		  {
		  	cout<<"Origen-Destino: "<<b->first<<endl;
		  	cout<<"Sus recorridos: "<<endl;
		  	cout<<"Distancia y Velocidad: "<<endl;
			  for(int i =0; i< b->second.size();++i)
		  	{
				cout<<b->second[i]<<endl;

			  }
			  b++;
		  }
		map<string, vector<int> >::iterator bi=alternativas.begin();
		  while(bi!=alternativas.end())
		  {
		  	cout<<"Origen-Destino: "<<bi->first<<endl;
		  	cout<<"Tiempo de Recorrido: "<<endl;
		  	float tiempo;
			  for(int i =0; i< bi->second.size()-1;i++)
		  	{
				tiempo=(bi->second[i])/(bi->second[i+1]);
				cout<<tiempo<<endl;

			  }
			  bi++;
		  }
	}
	
	void buscar(string origenDestino)
	{
		map<string, vector<int> >::iterator bb=alternativas.begin();
		  while(bb!=alternativas.end())
		  {
		  	cout<<"Origen-Destino: "<<bb->first<<endl;
		  	cout<<"Tiempo mas corto entre Origen-Destino: "<<endl;
			float corto = (bb->second[0])/(bb->second[1]); 
			  for(int i =2; i< bb->second.size()-2;++i)
		  	{
		  		float sig = (bb->second[i+1])/(bb->second[i+2]);
				if(sig<corto)
			{
				
				corto = sig;

			  }
			 
		  }
		  cout<<corto<<endl;
		   bb++;
	}

}
};

int main()
{
	Distancia * d = new Distancia();
	d->agregarOrigenDestino("Sant-Valp", 200, 100);
	d->agregarOrigenDestino("Sant-Valp", 130, 140);
	d->agregarOrigenDestino("Sant-Talc", 300, 150);
	d->agregarOrigenDestino("Sant-Talc", 500, 100);
	d->imprimir();
	d->buscar("Sant-Talc");

	return 0;
}