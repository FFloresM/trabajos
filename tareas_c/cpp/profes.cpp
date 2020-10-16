/*
La facultad de ingeniería pide a todos sus profesores registrar las fechas en que realizan sus evaluaciones (pruebas). 
Los profesores pueden pertenecer a sólo una de las siguientes escuelas: INDUSTRIA, OOCC, INFORMÁTICA y PLANCOMUN.

La información de los profesores y sus evaluaciones quedan registradas en la clase Pruebas.

En base a lo anterior se pide implementar las siguientes funciones de la clase Pruebas:

void imprimir(string escuela) que imprime las fechas de las pruebas de los profesores que pertenecen a la escuela que se ingresa como parámetro (NO SE DEBE LEER DE TECLADO, LA ESCUELA ES UN PARÁMETRO). Debe imprimir lo siguiente:

Rut Profesor: 99

Sus pruebas:

20200420
20200525

Rut Profesor: 88

20200421
20200528

Debe escoger una de las dos siguientes funciones 

void agregarEvaluacion(string rut, string escuela, int fecha), que agrega una evaluación del profesor de rut, escuela y fecha ingresados como parámetros (NO SE DEBE LEER DE TECLADO, LOS DATOS RUT Y FECHA SON PARÁMETROS)


int cuantasEvaluaciones(string rut), que devuelve el número de evaluaciones que ha realizado un profesor, si el profesor no existe devuelve -1. (NO SE DEBE LEER RUT DE TECLADO)

*/
class Pruebas
    {
     private:

         map<string, string> escuelas;    //tiene el rut del profesor y la escuela a la que pertenece
         map<string, vector <int> > evaluaciones; //tiene el rut del profesor y un vector con las fechas en formato YYYYMMDD

    public:

    	void imprimir(string escuela){
    		vector<string> profes;
    		map<string, int>::iterator it;
    		map<string, vector<int> >::iterator at;

			for ( it = escuelas.begin(); it != escuelas.end(); it++ ){
				if (it->second == escuela)
				{
					profes.push_back(it->first);
				}
			}
			for (int i = 0; i < profes.size(); i++){
				for ( at = evaluaciones.begin(); at != evaluaciones.end(); at++ ){
					if (profes[i] == at->first){
						cout << "Rut Profesor:"<< profes[i]<< endl;
						vector<int> evals = at->second;
						for (int j = 0; j < evals.size(); j++){
							cout << evals[j]<< endl;
						}
					}
				}
			}
    	}

    	int cuantasEvaluaciones(string rut){
    		//int contador = 0;
    		if (evaluaciones[string]){
    			vector<int> evals = evaluaciones[string];
    			return evals.size();
    		}else{
    			return -1;
    		}

    	}

};

