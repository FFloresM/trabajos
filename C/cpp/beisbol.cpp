#include<iostream> 
using namespace std;
int juego(string ops[], int opsLargo) 
{ 
    for(int i = 0; i < opsLargo; i++) {
         cout << ops[i] << endl; }
} 
int main() {
    string ops[5] = {"5", "2", "C", "D", "+"};
    cout << "La suma total es: " << juego(ops, 5) << endl; 
    return 0;
}