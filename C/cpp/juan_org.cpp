#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    map<string, vector<string>> cajas;
    string caja, nombre_herramienta;

    while(1){
        cout << "ingrese nombre de la caja: ";
        cin >> caja;
       
        if (caja != "termine")
        {
            cout << "ingrese nombre de la herramienta: ";
            cin >> nombre_herramienta;
            cajas[caja].push_back(nombre_herramienta);
        }
        else{
            break;
        }
        
    }

    map<string, vector<string>>::iterator it;
    cout << "ingrese nombre de la herramienta a cambiar de caja : ";
    cin >> nombre_herramienta;
    cout << "ingrese nombre de la caja: ";
    cin >> caja;
    for(it = cajas.begin(); it != cajas.end(); it++){
        for (int i = 0; i < it->second.size(); i++)
        {
            if(it->second[i] == nombre_herramienta){
                it->second.erase(it->second.begin()+ i);
            }
        }
        
    }

    cajas[caja].push_back(nombre_herramienta);

      for(it = cajas.begin(); it != cajas.end(); it++){
          cout << "nombre de la caja " << it->first << ":"<<endl;
        for (int i = 0; i < it->second.size(); i++)
        {
            cout << it->second[i] << endl;
            
        }
        
    }


    return 0;
}