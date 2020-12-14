#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    map<int, string> hrtas;
    string nombre;
    int cantidad;

    while(1){
        cout << "ingrese nombre de la herramienta: ";
        cin >> nombre;
        if (nombre != "termine")
        {
            cout << "ingrese cantidad: ";
            cin >> cantidad;
            hrtas[cantidad] = nombre;
        }
        else{
            break;
        }
        
    }

    map<int, string>::iterator it;
    int mayor = 0;
    cout << "total de hrtas: " << hrtas.size() << endl;
    for(it = hrtas.begin(); it != hrtas.end(); it++){
        cout << it->first << " " << it->second << endl;
        if (it->first > mayor)
        {
            mayor = it->first;
        }
        
    }
    cout << "La que tiene más cantidad es: " << hrtas[mayor] << endl;

    

    return 0;
}
