#include <iostream>

using namespace std;

string validarRUT(int RUT[], char digi){
    char p[] = {'k', '2', '3', '4', '5', '6', '7', '8', '9','0'};
    int suma=0;
    for (int i = 0; i < 8; i++)
    {
        if(RUT[i] != -1){
            suma++;
        }
    }
    if ((suma == 7 || suma==8) )
    {
        for (int i = 0; i < 10; i++)
        {
            if (digi == p[i])
            {
                return "VERDADERO";
            }
            
        }
        
    }
    
    
    return "FALSO";
}

int main(int argc, char const *argv[])
{
    int d[8];
    char t;
    cout << "ingrese digitos del rut antes del guión (separados por espacio): "<<endl;
    for (int i = 0; i < 8; i++)
    {
        cin >> d[i];
    }
    cout << "ingrese digito verificador:"<< endl;
    cin >> t;

    cout << validarRUT(d,t) << endl;
    return 0;
}
