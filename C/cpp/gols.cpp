#include <iostream>
#include <vector>
using namespace std;
class Jugador
  {
   private:
    string nombre;
    vector<string> equipos;
    vector<string> paises;
    vector<int> goles;
   public:
     Jugador(string nombre)
        {
        this->nombre = nombre;
    }
 string getNombre()
          {
    return nombre;
    }
void anotarGol(string nombreEquipo, string nombrePais)
   {
     int p=-1,k=-1;

       for (int j = 0; j < equipos.size(); j++)
               {
                   if (equipos[j] == nombreEquipo)
                   {
                       p = j;
                   }
                   
               }
       for (int i = 0; i < paises.size(); i++)
       {
           if (paises[i] == nombrePais)
           {
               k = i;
               
           }
           
       }

    if (k!=-1 && p!=-1)
    {
        goles[p] += 1;
    }else
    {
        equipos.push_back(nombreEquipo);
        paises.push_back(nombrePais);
        goles.push_back(1);
    }
    }
int golesMarcados()
  {
   //retorna la cantidad de goles marcados por el jugador
   int suma=0;
    for (int i = 0; i < goles.size(); i++)
    {
        suma+=goles[i];
    }
    return suma;
  }
int golesEnPais(string nombrePais)
  {
   //retorna la cantidad de goles que hizo a los equipos de un país
     int suma=0;
   for (int i = 0; i < paises.size(); i++)
   {
       if (paises[i] == nombrePais)
       {
           suma += goles[i];
       }
       
   }
   return suma;
  }
  };
  
int main()
 {
 Jugador *j = new Jugador("Maradona");
 j->anotarGol("River", "Argentina");
 j->anotarGol("Banfield", "Argentina");
 j->anotarGol("Juventus", "Italia");
 j->anotarGol("Inter", "Italia");
 j->anotarGol("Milan", "Italia");
 cout << j->getNombre() << " ha marcado " << j->golesMarcados() << " goles " << endl;
        cout << "Ha equipos Italianos le ha marcado " << j->golesEnPais("Italia") << " goles " << endl;
        return 0;
 }