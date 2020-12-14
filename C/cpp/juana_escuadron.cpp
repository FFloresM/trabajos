#include <map>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    map<string, vector<string>> escuadrones;
    string escuadron, nombre_soldado;

    while(true){
        cout << "ingrese nombre del escuadron: ";
        cin >> escuadron;
       
        if (escuadron != "termine")
        {
            cout << "ingrese nombre del soldado: ";
            cin >> nombre_soldado;
            escuadrones[escuadron].push_back(nombre_soldado);
        }
        else{
            break;
        }
        
    }

    map<string, vector<string>>::iterator iter;
    cout << "soldado a cambiar : ";
    cin >> nombre_soldado;
    cout << "nombre nuevo escuadron: ";
    cin >> escuadron;
    for(iter = escuadrones.begin(); iter != escuadrones.end(); iter++){
        for (int i = 0; i < iter->second.size(); i++)
        {
            if(iter->second[i] == nombre_soldado){
                iter->second.erase(iter->second.begin()+ i);
            }
        }
        
    }

    escuadrones[escuadron].push_back(nombre_soldado);

      for(iter = escuadrones.begin(); iter != escuadrones.end(); iter++){
          cout << "escuadrón " << iter->first << ":"<<endl;
        for (int i = 0; i < iter->second.size(); i++)
        {
            cout << iter->second[i] << endl;
            
        }
        
    }


    return 0;
}