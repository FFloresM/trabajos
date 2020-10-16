#include <iostream>

using namespace std;

void llenar_Matriz(int matriz[][100], int M){
	
	for (int i = 0; i < M; i++){
		for (int j = 0; j < M; j++){
			cout<< "ingrese valor "<<i<<" "<<j<<": ";
			cin >> matriz[i][j];
		}
	}
}

void cambiar_matriz(int matriz[][100], int M){
	int temp[M][M];
	for (int i=0 ; i < M; i++){
		for (int j=0 ; j < M; j++){
	    	temp[i][j] = matriz[i][j];
	  	}
	}

		for (int j = 0; j < M; j++){
			matriz[j][j] = temp[M-1][j];
			matriz[M-1][j] = temp[j][j];
		}
	cout <<endl;

}

int main()
{
	int M;
	cout <<"ingrese M: ";
	cin>>M;
	int matrix[M][100];
	llenar_Matriz(matrix, M);
	
	for (int i = 0; i < M; ++i){
		for (int j = 0; j < M; ++j){
			cout << matrix[i][j]<<" ";
		}
		cout <<endl;
	}
	cambiar_matriz(matrix,M);
	for (int i = 0; i < M; ++i){
		for (int j = 0; j < M; ++j){
			cout << matrix[i][j]<<" ";
		}
		cout <<endl;
	}
	return 0;
}
