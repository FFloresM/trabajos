class FabricantePerfume:
{
	private:
		string nombre;
		int anio;
		int valor_comercial;
		string pais;
		int puntaje_ranking; 

	public:
		FabricantePerfume(string nombre, int anio, int vc, int pais, int pr){
			this->nombre = nombre;
			this->anio = anio;
			this->valor_comercial = vc;
			this->pais = pais;
			this->puntaje_ranking = pr;
		}

		string getNombre(){
			return nombre;
		}
		int getAnio(){
			return anio;
		}
		int getValorComercial(){
			return valor_comercial;
		}
		string getPais(){
			return pais;
		}
		int getPuntajeRanking(){
			return puntaje_ranking;
		}
	
	
};

class CampeonatoPerfumes
{
	private:
		std::vector<FabricantePerfume *> fabricantes;
		map<string,int> puntajes;
		vector<int> puntos = {16,8,4,2,1};


	public:
		CampeonatoPerfumes();
 		void ingresarResultadoCompetencia(queue<string> CK){
 			for (int j = 0; j < puntos.size(); j++)
 				for (int i = 0; i < fabricantes.size(); i++)
 				{
 					if(fabricantes[i].nombre == CK.front()){
 						fabricantes[i].puntaje_ranking+=puntos[j];
 						CK.pop();
 						break;
 					} 
 				}
	 			
 		}

	
	
};