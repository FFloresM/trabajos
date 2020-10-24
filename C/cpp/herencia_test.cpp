#include <iostream>
using namespace std;

class A {

 private:
 	int x;

public:
 A(int x){
 	this->x=x;
 }
 int getX(){return this->x;}
 void setX(int x){this->x = x;}
 auto max(A *a){
 	if (this->getX() > a->getX() )
 	{
 		return this;
 	}else{
 		return a;
 	}
 }
};


int main()
{
 
 A *a = new A(10);
 A *a_ = new A(20);

 A *_a = a->max(a_);
 cout << _a->getX()<<endl; 
 cout << a <<endl;

return 0;
}