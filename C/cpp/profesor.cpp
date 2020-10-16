/*
clase padre: Profesor
	atributos:
		rut
		nombre completo
		tipo

clase hijo: Completa hereda de: Profesor
	atributos:
		AFP
		Isapre
		grado académico
		especialización

clase hijo: Parcial hereda de: Profesor
	atributos:
		AFP
		Isapre
		tipoJornada
		otroTrabajo

clase hijo: PorHoras hereda de: Profesor
	atributos:
		numero de asignaturas
*/
#include <iostream>
using namespace std;

class Profesor
{
	private:
		string rut;
		string nombre_completo;
		string tipo;
	public:
		Profesor(string rut, string nombre_completo, string tipo){
			this->rut=rut;
			this->nombre_completo = nombre_completo;
			this->tipo = tipo;
		}

		void imprimir(){
			cout << rut <<" "<<nombre_completo<<" "<< tipo << endl;
		}
	
};

class Completa: public Profesor
{
	private:
		string AFP;
		string isapre;
		string grupo_academico;
		string especializacion;

	public:
		Completa(string rut, string nombre_completo, string tipo, string AFP, string isapre, string grupo_academico, string especializacion){
			this->rut=rut;
			this->nombre_completo = nombre_completo;
			this->tipo = tipo;
			this->AFP = AFP;
			this->isapre = isapre;
			this->grupo_academico = grupo_academico;
			this->especializacion = especializacion;
		}

		void imprimir(){
			Profesor::imprimir();
			cout<< AFP <<" "<<isapre<<" "<<grupo_academico<<" "<< especializacion<<endl;
		}
};

class Parcial: public Profesor
{
	private:
		string AFP;
		string isapre;
		string tipoJornada;
		string otroTrabajo;

	public:
		Parcial(string rut, string nombre_completo, string tipo, string AFP, string isapre, string tipoJornada, string otroTrabajo){
			this->rut=rut;
			this->nombre_completo = nombre_completo;
			this->tipo = tipo;
			this->AFP = AFP;
			this->isapre = isapre;
			this->tipoJornada = tipoJornada;
			this->otroTrabajo = otroTrabajo;
		}

		void imprimir(){
			Profesor::imprimir();
			cout<< AFP <<" "<<isapre<<" "<<tipoJornada<<" "<< otroTrabajo<<endl;
		}
};

class PorHoras: public Profesor
{
	private:
		int numero_asignaturas;

	public:
		PorHoras(string rut, string nombre_completo, string tipo, int numero_asignaturas){
			this->rut=rut;
			this->nombre_completo = nombre_completo;
			this->tipo = tipo;
			this->numero_asignaturas = numero_asignaturas;
		}

		void imprimir(){
			Profesor::imprimir();
			cout << numero_asignaturas<<endl;
		}
};

class Profesorado
{
	private:
		Profesor profesores[10];
		int i=0;

	public:
		void agregarProfesor(Profesor *p){
			profesores[i] = p;
			i++;
		}

		void listarProfesores(){
			for (int i = 0; i < 10; ++i)
			{
				profesores[i].imprimir();
			}
		}
};

int main()
{
	Completa *comp = new Completa("1234", "pancho malo", "JC", "provida", "banmedica", "infomatica", "estructuras de dats"); 
	return 0;
}