#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Item
{

private:
	string nombre;
	string kind_of_damage;
	int precio;
	int damage;
	

public:
	Item(string n, int p, string kofd, int d){
		precio = p;
		nombre = n;
		damage = d;
		kind_of_damage = kofd;
	}

	string getNombre()const{
		return nombre;
	}

	int getPrecio() const{
		return precio;
	}

	int getDamage()const{
		return damage;
	}

	string getKindOfDamage()const{
		return kind_of_damage;
	}

	void imprimir()const{
		cout <<"nombre: " << getNombre() << endl
			 <<"precio: " << getPrecio() << endl
			 <<"daño: " << getDamage() << endl
			 <<"Tipo de daño: " << getKindOfDamage() << endl;
	}

	
};

class myComparison
{
public:
    bool operator() (Item item1, Item item2)
    {
        return item1.getPrecio() > item2.getPrecio();
    }
};

class Pagina
{
private:
	priority_queue<Item, vector<Item>, myComparison> items;

public:
	priority_queue<Item, vector<Item>, myComparison> getItems(){
		return items;
	}

	void addItem(Item item){
		items.push(item);
	}

	void despliegue(){
		priority_queue<Item, vector<Item>, myComparison> pq = getItems();
		while(!pq.empty()){
			pq.top().imprimir();
			pq.pop();
		}
		cout << endl;
	}

	void removeItem(string nombre){
		vector<Item> temp;
		while(!items.empty()){
			if (items.top().getNombre() != nombre){
				temp.push_back(items.top());
				items.pop();
			}
		}
		for (int i = 0; i < temp.size(); ++i){
			addItem(temp[i]);
		}
	}

	void comproTodo(int precio){
		vector<string> nombres;
		int acum=0;
		while(true){
			if (acum + items.top().getPrecio() < precio){
				acum += items.top().getPrecio();
				nombres.push_back(items.top().getNombre());
				items.pop();
			}else{
				break;
			}
			
		}
		cout <<"puede comprar";
		for (int i = 0; i < nombres.size(); i++){
			cout<< " " << nombres[i] << ",";
		}
		cout << " y suma " << acum << endl;

		
	}

};

class Tienda
{
private:
	vector<vector<Pagina>> paginas{{},{},{},{}};
public:
	
	void agregarPagina(Pagina P, int i){
		paginas[i].push_back(P);
	}

	void menu(){
		cout << "Seleecione página" << endl
			 << "0 Defensa" << endl
			 << "1 Mágico" << endl
			 << "2 Físico" << endl
			 << "3 Crítico" << endl;
		int pagina;
		cin >> pagina;
		for (int i = 0; i < paginas[pagina].size(); i++){
			paginas[pagina][i].despliegue();
		}
		
		}

		vector<Pagina> getPaginas(int i){
			return paginas[i];
		}
	
};

class PaginaFisico: public Pagina{};

class PaginaDefensa: public Pagina{};

class PaginaMAgico: public Pagina{};

class PaginaCritico: public Pagina{};

int main(void)
{
	Item catapulta = Item("catapulta", 1000, "Físico", 500);
	Item daga = Item("daga", 250, "Físico", 50);
	Item hacha = Item("hacha", 400, "Físico", 100);
	Item veneno = Item("veneno", 400, "Mágico",  300);
	Item hechizo = Item("hechizo", 300, "Magico", 200);
	Item embrujo = Item("embrujo", 250, "Magico", 100);

	PaginaMAgico magico;
	PaginaFisico fisico;
	fisico.addItem(daga);
	fisico.addItem(hacha);
	fisico.addItem(catapulta);
	magico.addItem(veneno);
	magico.addItem(hechizo);
	magico.addItem(embrujo);

	Tienda nueva_tienda;
	nueva_tienda.agregarPagina(fisico,2);
	nueva_tienda.agregarPagina(magico,1);
	nueva_tienda.menu();
	nueva_tienda.getPaginas(1)[0].comproTodo(1000);
	nueva_tienda.getPaginas(2)[0].comproTodo(2000);


	return 0;
}