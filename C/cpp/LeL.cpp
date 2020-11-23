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
			this->danio = dnaio;
			this->tipo_danio = tipo_danio; 
		}

		string getNombre(){
			return this->nombre;
		}

		int getPrecio(){
			return this->precio;
		}

	
};

class Tienda{
	private:
		vector<vector<int>> paginas;
	public:
		Tienda();
	
};

class myComparison
{
public:
    bool operator() (const Item& it1, const Item& it2)
    {
        return it1.getPrecio() > it2.getPrecio();
    }
};

class Pagina{
	private:
		string tipo_danio;
		priority_queue<Item, vector<Item>, myComparison> items;
	public:
		Pagina(string tipo_danio){
			this->tipo_danio = tipo_danio;
		}

		priority_queue<Item> getItems(){
			return items;
		}

		void addItem(Item item){
			this->items.push(item);
		}

		void despliegue(priority_queue<Item> pq){
			while(!pq.empty()){
				cout << " " << pq.front();
				pq.pop();
			}
			cout << endl;
		}

		bool removeItem(string nombreItem){
			vector<Item> aux;
			while(!this->items.empty()){
				if (this->items.top()->getNombre() != nombreItem){
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
			while(TRUE){
				if (suma < valor){
					suma += this->items.top().getPrecio();
					nombres.push_back(this->items.top().getNombre());
					this->items.pop();
				}else{
					break;
				}
				
			}
			//imprimir
			
		}

};