#include <iostream>

using namespace std;

void menosUtilizado(int arr[4][7]){
	int min=999999, row, col;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 7; j++){
			if (arr[i][j]<min){
				min = arr[i][j];
				row = i;
				col = j;
			}
		}
	}
	cout << "el menos utilizado se encuentra en ("<<row<<","<<col<<")"<<endl;
}

int masQueElPromedio(int arr[4][7]){
	int promedio = 0, suma=0, count=0;
	//calculo promedio
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 7; j++){
			suma+=arr[i][j];
		}
	}
	promedio = suma/(4*7);
	cout <<"promedio "<< promedio<<endl;
	//mayores a promedio
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 7; j++){
			if (arr[i][j] > promedio){
				count++;
			}
		}
	}
	cout << "se utilizaron más que el promedio: ";
	return count;
}

void masGano(int arr1[4][7], int arr2[4][7]){
	int total = 0, utilidad, row, col;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 7; j++){
			utilidad = arr1[i][j]*arr2[i][j];
			if (utilidad>total){
				total = utilidad;
				row = i;
				col = j;
			}
		}
	}
	cout << "El estacionamiento que más ganó es el ("<<row<<","<<col<<")"<<endl;
}

int main(){
	int Usos[4][7] = {
		{12,12,33,14,15,12,7},
		{11,21,13,4,15,6,2},
		{19,3,4,1,2,3,2},
		{21,32,13,14,25,36,14}
	};
	int Precios[4][7] = {
		{110,123,33,45,58,16,70},
	 	{45,23,56,43,67,77,9}, 
	 	{65,45,44,32,74,89,76}, 
	 	{98,289,75,34,24,67,33}
	 };
	
	menosUtilizado(Usos);
	cout << masQueElPromedio(Usos) << endl;
	masGano(Usos, Precios);
		
	return 0;
}