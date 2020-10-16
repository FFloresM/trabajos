#include <iostream>

using namespace std;

void llenarA(int arr[], int n){
	cout <<"ingrese "<<n<<" valores pares:\n";
	int v;
	int i = 0;
	while(1){
		cin >> v;
		if (v%2==0){
			arr[i] = v;
			i++;
		}else{
			cout << "debe ser par"<<endl;
		}
		if (i==n) break; 
	}
}

void llenarB(int arr[], int n){
	int v;
	cout <<"ingrese "<<n<<" valores impares:\n";
	int i=0;
	while(1){
		cin >> v;
		if (v%2==1){
			arr[i] = v;
			i++;
		}else{
			cout << "debe ser impar"<<endl;
		}
		if (i==n) break; 
	}
}

void sumar(int arr1[], int arr2[], int suma[], int n){
	for (int i = 0; i < n; i++){
		suma[i] = arr1[i]+arr2[i];
	}
}

void mostrar_arr(int arr[], int n, string msg){
	cout <<msg<<endl;
	for (int i = 0; i < n; i++){
		cout << arr[i]<<" ";
	}
	cout << endl;
}

int main()
{
	int n;
	while (1){
		cout << "ingrese n: ";
		cin >> n;
		if (n>0)
			break;
	}
	int A[n], B[n], suma[n];
	llenarA(A,n);
	llenarB(B,n);
	sumar(A,B,suma,n);
	mostrar_arr(A,n,"A");
	mostrar_arr(B,n,"B");
	mostrar_arr(suma,n, "La suma es");
	return 0;
}