#include <iostream>
using namespace std;

class Empresa
{
	protected:
		string nombre;
		int rut;
		string direccion;
		int anos;
		int salario;
	public:
		Empresa(string nombre, int rut, string direccion, int anos, int salario)
		{
			this->nombre=nombre;
			this->rut=rut;
			this->direccion=direccion;
			this->anos=anos;
			this->salario=salario;
		}
		
		string 	getNombre(){return nombre;}
		int getRut(){return rut;}
		string getDireccion(){return direccion;}
		int getAnos(){return anos;}
		int getSalario(){return salario;}
		
		void setNombre(string nombre){this->nombre=nombre;}
		void setRut(int rut){this->rut=rut;}
		void setDireccion(string direccion){this->direccion=direccion;}
		void setAnos(int anos){this->anos=anos;}
		void setSalario(int salario){this->salario=salario;}

		void imprimir(){
			cout << "Nombre: " << getNombre()<<endl << "Rut: " << getRut()<<endl << "direccion: " << getDireccion()<<endl << "años: " << getAnos()<<endl << "salario: " << getSalario()<<endl;
		}
};

class Ejecutivos:public Empresa
{
	private:
		int numoficina;
	public:
		Ejecutivos(string nombre, int rut, string direccion, int anos, int salario, int numoficina):Empresa(nombre, rut, direccion, anos, salario)
		{
			this->numoficina=numoficina;
		}
	
	int getNumoficina(){return numoficina;}
	
	void setNumoficina(int numoficina){this->numoficina=numoficina;}

	void imprimir(){
		Empresa::imprimir();
		cout << "numero oficina: "<< getNumoficina()<<endl;
	}
};

class Secretario:public Empresa
{
	private:
		int numfijo;
		int fax;
	public:
		Secretario(string nombre, int rut, string direccion, int anos, int salario, int numfijo, int fax):Empresa(nombre, rut, direccion, anos, salario)
		{
			this->numfijo=numfijo;
			this->fax=fax;
		}
		
	int getNumfijo(){return numfijo;}
	int getFax(){return fax;}
	
	void setNumfijo(int numfijo){this->numfijo=numfijo;}
	void setFax(int fax){this->fax=fax;}

	void imprimir(){
		Empresa::imprimir();
		cout << "numero fijo: "<< getNumfijo() << endl << "fax: " << getFax()<<endl;
	}
};

class Vendedores:public Empresa
{
	private:
		int numcelu;
		string zonaventa;
	public:
		Vendedores(string nombre, int rut, string direccion, int anos, int salario, int numcelu, string zonaventa):Empresa(nombre, rut, direccion, anos, salario)
		{
			this->numcelu=numcelu;
			this->zonaventa=zonaventa;
		}
		
	int getNumcelu(){return numcelu;}
	string getZonaventa(){return zonaventa;}
	
	void setNumcelu(int numcelu){this->numcelu=numcelu;}
	void setZonaventa(string zonaventa){this->zonaventa=zonaventa;}
	void imprimir(){
		Empresa::imprimir();
		cout << "numero celular: "<<getNumcelu()<<endl<< "zona venta: "<<getZonaventa()<<endl;
	}
};

int main()
{
	Empresa *empleado = new Empresa("Pancho", 12345678, "agua verde 123, Conce", 25, 150000);
	empleado->imprimir();

	Ejecutivos *ejecutivo = new Ejecutivos("Lucho", 12333679, "agua azul 456, Lota", 27, 200000, 005);
	ejecutivo->imprimir();

	Secretario *secretario = new Secretario("Paco", 90333679, "agua turbia 308, Thno", 30, 250000, 412456798, 442345691);
	secretario->imprimir();

	Vendedores *vendedor = new Vendedores("Hugo", 20444678, "agua negra 666, Calama", 30, 300000, 945675674, "Menaje");
	vendedor->imprimir();
	return 0;
}