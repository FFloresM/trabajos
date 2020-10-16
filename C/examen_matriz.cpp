#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void llenarMAtriz(int matriz[][100], int M, int N){
	
	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			matriz[i][j] = rand()%10;
		}
	}
}

void cambiarMatriz(int matriz[][100], int M, int N){
	int vector[2*M];
	int temp[M][N];
	//copia
	for (int x=0 ; x < M; x++){
		for (int y=0 ; y < N; y++){
	    	temp[x][y] = matriz[x][y];
	  	}
	}

	for (int j = 0; j < N; j++){
		matriz[0][j] = temp[M-1][j];
		matriz[M-1][j] = temp[0][j];
	}

	for (int i = 0; i < M; i++){
		vector[i] = matriz[0][i];
		vector[i+M] = matriz[M-1][i];
	}

	for (int i = 0; i < 2*M; i++){
		cout<<vector[i]<< " ";
	}
	cout <<endl;

}

int main()
{
	int filas, cols;
	cout <<"ingrese M: ";
	cin>>filas;
	cout << "\ningrese N: ";
	cin>>cols;
	cout <<endl;
	cout << filas << cols<<endl;
	int matrix[filas][100];
	llenarMAtriz(matrix, filas, cols);
	
	for (int i = 0; i < filas; ++i){
		for (int j = 0; j < cols; ++j){
			cout << matrix[i][j]<<" ";
		}
		cout <<endl;
	}
	cambiarMatriz(matrix,filas,cols);
	return 0;
}

