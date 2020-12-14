#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Insumo
  {
   private:  	
   	  string nombreIQ;
   	  string um;
   	  int stock;
   public:
   	Insumo(string nombre,string um){
   		this->stock=0;
   		this->nombreIQ=nombre;
   		this->um=um;
	   }
	   string getnombreIQ(){
	   	return nombreIQ;
	   }
	   string getUnidadMedida(){
	   	return um;
	   }
	   int getstock(){
	   	return stock;
	   }
	   void setStock(int cant){
	   	this->stock=cant;
	   }
  };
class Consumo
  {
  	private:
  		string nombreIQ;
  		int cantidadConsumida;
  		int fecha;
  	public:
  		Consumo(string nombre,int cantidad,int fecha){
  			this->nombreIQ=nombre;
  			this->cantidadConsumida=cantidad;
  			this->fecha=fecha;
		  }
		 string getNombre(){
		 	return nombreIQ;
		 } 
		 int getcantconsumida(){
		 	return cantidadConsumida;
		 }
		 int getFecha(){
		 	return fecha;
		 }
		};  	
class Produccion
  {
  	private:
  		map<string, vector<Insumo * > > listaIQPlanta; 
  		map<string, vector<Consumo * > > listaCOPlanta;
  		
  	public:
  		Produccion(){
		  }
		  void agregarPlanta(string nombre){  
		  	if(listaIQPlanta.find(nombre)==listaIQPlanta.end()){ 
		  		vector<Consumo *> Consumos;
				  vector<Insumo *> Insumos;
		  		
		  		listaIQPlanta[nombre]=Insumos;
		  		listaCOPlanta[nombre]=Consumos;
		  		
		  		
			  }
		  }
		  void agregarInsumoAPlanta(string nombrePlanta,Insumo *p){ 
		  int aux=0;
		  	for(int j=0;j<listaIQPlanta[nombrePlanta].size();j++){
		  		if(p->getnombreIQ()==listaIQPlanta[nombrePlanta].at(j)->getnombreIQ()){
		  			aux=1;
		  			cout<<"planta"<<nombrePlanta<<" ya existe"<<endl;
				  }
			  }
			  if(aux==0){
			  	listaIQPlanta[nombrePlanta].push_back(p);
			  	cout<<"insumo ingresado"<<endl; 
			  }		 
}
			  void agregarConsumoAPlanta(string nombrePlanta,Consumo *p){ 
			  int aux=0;
			  		for(int i=0;i<listaCOPlanta[nombrePlanta].size();i++){
			  			if(listaCOPlanta[nombrePlanta].at(i)->getNombre()==p->getNombre() && listaCOPlanta[nombrePlanta].at(i)->getFecha()==p->getFecha()){
			  				cout<<"Consumo ya fue registrado"<<endl;
			  				aux=1;
							  }
			  }
			  if(aux==0){
			  	listaCOPlanta[nombrePlanta].push_back(p);
			  	cout<<"Consumo correctamente registrado "<<endl;
			  		int aux=0;
			  }
			  }
			  void listarPlantas(){ 
			  	map<string, vector<Insumo * > >::iterator recorre;
			  	for(recorre=listaIQPlanta.begin();recorre != listaIQPlanta.end();recorre++){
			  		cout<<" Nombre: "<<recorre->first<<endl;
				  }
			  }
			  void listarNombreInsumos(string nombrePlanta){ 
			  	map<string, vector<Insumo * > >::iterator ite;
			  	for(ite=listaIQPlanta.begin();ite!=listaIQPlanta.end();ite++){
			  		if(ite->first==nombrePlanta){
			  			for(int i=0;i<ite->second.size();i++){
			  			cout<<ite->second.at(i)->getnombreIQ()<<endl;
					  }
					  }		
				  }
			  }		  
			  void stockInsumoPlanta(string nombrePlanta, string nombreInsumo){
			  map<string, vector<Insumo * > >::iterator ite;
			  for(ite=listaIQPlanta.begin();ite!=listaIQPlanta.end();ite++){
			  	if(ite->first==nombrePlanta){
			  		for(int i=0;i<ite->second.size();i++){
			  			if(ite->second.at(i)->getnombreIQ()==nombreInsumo){
			  				cout<<"Stock:"<<ite->second.at(i)->getstock()<<endl;			  				
						  }
					  }
				  }
			  }
			  }
			  int enPlantas(string nombreInsumo){
			  	map<string, vector<Insumo * > >::iterator ite;
			  	int contador=0;
			  	for(ite=listaIQPlanta.begin();ite!=listaIQPlanta.end();ite++){
			  		for(int i=0;i<ite->second.size();i++){
			  			if(ite->second.at(i)->getnombreIQ()==nombreInsumo){
			  				contador++;
						  }
					  }
				  }
				  cout<<contador;
			  }	};
main()
 {
  	Produccion *p = new Produccion();
  	int opcion;
cout<<"1. Agregar Planta"<<endl;
cout<<"2. Agregar Insumo a Planta"<<endl;
cout<<"3. Agregar Consumo a Planta"<<endl;
cout<<"4. Listar Plantas"<<endl;
cout<<"5. Listar Insumos de una Planta"<<endl;
cout<<"6. Stock de insumo en una Planta"<<endl;
cout<<"7. Cantidad de insumo en todas las plantas"<<endl;
cin>>opcion;
if(opcion==1){
	string nombrePlanta;
	cout<<"Digite nombre de planta:";cin>>nombrePlanta;
	p->agregarPlanta(nombrePlanta);
}
if(opcion==2){
	string nombrePlanta;
	cout<<"Digite nombre de la planta:"<<endl;
	cin>>nombrePlanta;
	string insumo;
	cout<<"Digite nombre del Insumo:"<<endl;
	cin>>insumo;
	string UM;
	cout<<"Digite Unidad de Medida: "<<endl;
	cin>>UM;
	int cant;
	cout<<"Digite Stock :"<<endl;
	cin>>cant;
	Insumo *n = new Insumo(insumo,UM);
	p->agregarInsumoAPlanta(nombrePlanta,n);
}
if(opcion==3){
	string nombrePlanta;
	cout<<"Digite nombre de la planta:"<<endl;
	cin>>nombrePlanta;
	string nombreInsumo;
	cout<<"Ingrese nombre del insumo consumido :"<<endl;
	cin>>nombreInsumo;
	int fecha;
	cout<<"Digite fecha: "<<endl;
	cin>>fecha;
	int cantidad;
	cout<<"Digite cantidad consumida:"<<endl;
	cin>>cantidad;
	Consumo *c = new Consumo(nombreInsumo,cantidad,fecha);
	p->agregarConsumoAPlanta(nombrePlanta,c);
}
if(opcion==4){
	p->listarPlantas();
}
if(opcion==5){
	string nombrePlanta;
	cout<<"Digite nombre:"<<endl;
	cin>>nombrePlanta;
	p->listarNombreInsumos(nombrePlanta);
}
if(opcion==6){
	string nombrePlanta;
	cout<<"Digite nombre de planta: "<<endl;
	cin>>nombrePlanta;
	string insumo;
	cout<<"Digite nombre de insumo:"<<endl;
	cin>>insumo;
	p->stockInsumoPlanta(nombrePlanta,insumo);
}
if(opcion==7){
	string insumo;
	cout<<"Digite nombre de insumo: ";cin>>insumo;
	p->enPlantas(insumo);
}
}