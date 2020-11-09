#include <iostream>

using namespace std;

int main(){

float x1,y1,b1,x2,y2,b2,M,Mx,My,x,y;

cout<<" sistema de ecuaciones 2x2"<<endl;
cout<<"primera ecuacion"<<endl;
cout<<"valor de x1: "<<endl;
cin>>x1;
cout<<"valor de y1: "<<endl;
cin>>y1;
cout<<"inserta b1: "<<endl;
cin>>b1;
cout<<endl<<endl;
cout<<"segunda ecuacion"<<endl;
cout<<"valor de x2: "<<endl;
cin>>x2;
cout<<"valor de y2: "<<endl;
cin>>y2;
cout<<"inserta b2: "<<endl;
cin>>b2;
cout<<endl<<endl;
M = x1*y2-(x2*y1);
Mx = b1*y2-(b2*y1);
My = x1*b2-(x2*b1);

y = My/M;
x = Mx/M;

cout<<"EL VALOR DE Y ES: "<<y<<endl;
cout<<"EL VALOR DE X ES: "<<x<<endl;

return 0;
}