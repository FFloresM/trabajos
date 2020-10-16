#include <iostream>
#include <map>

using namespace std;

class Contagios
{
	private:
		map<string, int> contagiadosalafecha;
		map<string, int> fallecidosalafecha;

	public:
		void agregarDia(string comuna, int contagios, int fallecidos)
	{
	//programe el método agregar día. El método recibe, para un dia, los
	//contagios y, lamentablemente, el número de fallecidos de un día
	//cada map se actualiza, sumando los contagios y fallecidos
	//si la comuna no existe se crea con la información respectiva
	//la próxima vez sólo se actualiza
		contagiadosalafecha[comuna] += contagios;
		fallecidosalafecha[comuna] += fallecidos;

	}

	void imprimePorcentaje()
	{
		//este método imprime para cada comuna el porcentaje de fallecidos
		//c/r a los contagios
		//debe imprimir
		//comuna %fallecido c/r a contagios
		map<string,int>::iterator it, at;

		for (it=contagiadosalafecha.begin(), at = fallecidosalafecha.begin(); it!=contagiadosalafecha.end(), at!=fallecidosalafecha.end(); ++it,++at){
    		cout << it->first << " " << (float(at->second)/float(it->second))*100 <<"%"<< '\n';
    	}
	 
	}
};

int main()
{
	//ejemplo ejecución y salida
	Contagios *c = new Contagios();
	c->agregarDia("santiago", 100, 2);
	c->agregarDia("santiago", 90, 5);
	c->agregarDia("puente alto", 120, 5);
	c->agregarDia("puente alto", 100, 4);
	c->imprimePorcentaje();
	//debe imprimir
	//santiago 3,6842%
	//puente alto 4,09090% 
	return 0;
}