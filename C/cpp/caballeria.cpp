#include <iostream>
#include <vector>

using namespace std;

class Caballeria{
    private:
        string nombre;
        vector<string> soldados;
        vector<string> armas;

    public:
        Caballeria(string nombre, vector<string> soldados, vector<string> armas){
            this->nombre = nombre;
            this->soldados = soldados;
            this->armas = armas;
        }

        Caballeria(string nombre){
            this->nombre = nombre;
        }

        void agregarSoldado(string soldado){
            this->soldados.push_back(soldado);
        }

        void agregarArmas(string arma){
            this->armas.push_back(arma);
        }

        void quitarSoldado(string soldado){
            for (int i = 0; i < this->soldados.size(); i++){
                if (soldado == this->soldados[i])
                {
                    this->soldados.erase(this->soldados.begin()+i);
                    break;
                }
                
            }
            
        }

        void quitarArma(string arma){
            for (int i = 0; i < this->armas.size(); i++){
                if (arma == this->armas[i])
                {
                    this->armas.erase(this->armas.begin()+i);
                    break;
                }
                
            }
        }

        void cantidad(string nombre){
            if (nombre == "armas")
            {
                cout << "cantidad de armas: "<< this->armas.size() << endl;
                if (this->armas.size() > this->soldados.size() )
                {
                    cout << "faltan soldados"<< endl;
                }
                else if(this->armas.size() < this->soldados.size()){
                    cout << "faltan armas"<< endl;
                }
                
            }
            else if (nombre == "soldados")
            {
                cout << "cantidad de soldados: "<< this->soldados.size()<< endl;
                if (this->armas.size() > this->soldados.size() )
                {
                    cout << "faltan soldados"<< endl;
                }
                else if(this->armas.size() < this->soldados.size()){
                    cout << "faltan armas"<< endl;
                }
            }
            
            
        }
};

int main(){

    string nombre;
    cout << "ingrese nombre caballeria: ";
    cin >> nombre;
    Caballeria cab(nombre);
    string arma, soldado;
    while(true){
        cout << "ingrese soldados:"<<endl;
        cin >> soldado;
        if (soldado != "termine")
        {
            cab.agregarSoldado(soldado);
        }
        else{
            break;
        }
        
    }

    while(true){
        cout << "ingrese arma:"<<endl;
        cin >> arma;
        if (arma != "termine")
        {
            cab.agregarArmas(arma);
        }
        else{
            break;
        }
        
    }

    string n;
    cout << "armas o soldados?: ";
    cin >> n;

    cab.cantidad(n);
   

    return 0;
}