#include <iostream>
#include <vector>
#include <queue> // std::priority_queue


using namespace std;

class Item{

	private:
		int precio;
		string nombre;
		int danio;
		string tipo_danio; //defensa, magico, fisico, critoco

	public:
		Item(int precio, string nombre, int danio, string tipo_danio){
			this->precio = precio;
			this->nombre = nombre;
			this->danio = danio;
			this->tipo_danio = tipo_danio; 
		}

		string getNombre() const{
			return this->nombre;
		}

		int getPrecio() const{
			return this->precio;
		}

		int getDanio() const{
			return this->danio;
		}

		string getTipoDanio() const{
			return this->tipo_danio;
		}

		void show() const{
			cout << this->getNombre() << endl
				 << this->getPrecio() << endl
				 << this->getDanio() << endl
				 << this->getTipoDanio() << endl << endl;
		}

	
};

//clase para la cola de prioridad que ordena de menor a mayor
class myComparison
{
public:
    bool operator() (Item it1, Item it2)
    {
        return it1.getPrecio() > it2.getPrecio();
    }
};

class Pagina{
	private:
		priority_queue<Item, vector<Item>, myComparison> items;

	public:

		priority_queue<Item, vector<Item>, myComparison> getItems(){
			return this->items;
		}

		void addItem(Item item){
			this->items.push(item);
		}

		void despliegue(){
			priority_queue<Item, vector<Item>, myComparison> pq = this->getItems();
			while(!pq.empty()){
				pq.top().show();
				pq.pop();
			}
			cout << endl;
		}

		void removeItem(string nombreItem){
			vector<Item> aux;
			while(!this->items.empty()){
				if (this->items.top().getNombre() != nombreItem){
					aux.push_back(this->items.top());
					this->items.pop();
				}
			}
			for (int i = 0; i < aux.size(); ++i){
				this->addItem(aux[i]);
			}
		}

		void comproTodo(int valor){
			vector<string> nombres;
			int suma=0;
			while(true){
				if (suma + this->items.top().getPrecio() < valor){
					suma += this->items.top().getPrecio();
					nombres.push_back(this->items.top().getNombre());
					this->items.pop();
				}else{
					break;
				}
				
			}
			cout << "con " << valor << " puede comprar";
			for (int i = 0; i < nombres.size(); ++i){
				cout<< " " << nombres[i];
			}
			cout << " que suman " << suma << endl;

			
		}

};

class Tienda{
	private:
		vector<vector<Pagina>> paginas{{},{},{},{}}; //son 4 tipo de daño
	public:
		
		void addPagina(Pagina P, int i){
			this->paginas[i-1].push_back(P);
		}

		void menu(){
			int cat;
			cout << "Indique la página a la que quiere acceder" << endl
				 << "1 Defensa" << endl
				 << "2 Mágico" << endl
				 << "3 Físico" << endl
				 << "4 Crítico" << endl;
			cin >> cat;
			for (int i = 0; i < paginas[cat-1].size(); ++i){
				paginas[cat-1][i].despliegue();
			}
			
 		}

 		vector<vector<Pagina>> getPaginas(){
 			return this->paginas;
 		}
	
};

class PaginaFisico: public Pagina{};

class PaginaDefensa: public Pagina{};

class PaginaMAgico: public Pagina{};

class PaginaCritico: public Pagina{};


int main()
{
	Item espada = Item(700, "espada", 100, "Físico");
	Item hacha = Item(500, "hacha", 300, "Físico");
	Item guillotina = Item(1000, "guillotina", 500, "Físico");
	Item posion = Item(400, "posion", 100, "Mágico");

	PaginaFisico fisico;
	fisico.addItem(espada);
	fisico.addItem(hacha);
	fisico.addItem(guillotina);

	Tienda mitienda;
	mitienda.addPagina(fisico,3);
	mitienda.menu();
	mitienda.getPaginas()[2][0].comproTodo(2000);

	return 0;
}
