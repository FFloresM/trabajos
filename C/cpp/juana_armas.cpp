#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    map<int, string> armas;
    string nombre_arma;
    int cantidad;

    while(true){
        cout << "nombre arma: ";
        cin >> nombre_arma;
        if (nombre_arma != "termine")
        {
            cout << "ingrese cantidad de "<< nombre_arma <<": ";
            cin >> cantidad;
            armas[cantidad] = nombre_arma;
        }
        else{
            break;
        }
        
    }

    map<int, string>::iterator iter;
    int max = 0;
    cout << "total armas: " << armas.size() << endl;
    for(iter = armas.begin(); iter != armas.end(); iter++){
        cout << iter->first << " " << iter->second << endl;
        if (iter->first > max)
            max = iter->first;
    }
    cout << "La mayor cantidad es: " << armas[max] << endl;

    

    return 0;
}
