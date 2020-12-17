#include <stdio.h>
#define row 100
#define col 5
struct unidad{
    int codigo;
    char producto[20];
    int stock_minimo;
    int stock_maximo;
    int stock_actual;

};

void stock(struct unidad prod[row][col]){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){  
            printf("repisa %d, ubicación %d", i, j,);
            if (prod[i][j].stock_actual <= prod[i][j].stock_minimo*1.1)
            {
                printf("articulo %s", prod[i][j].producto );
                printf("codigo %d", prod[i][j].codigo);
                printf("cantidad a reponer %d",prod[i][j].stock_maximo - prod[i][j].stock_actual);
            }
            else{
                prinf("No requiere reposición");
            }
            
        }
        
    }
    
}

int main()
{
    struct unidad productos[row][col];
    stock(productos);

    return 0;
}
