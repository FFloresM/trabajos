#include <stdio.h>

int menu_ppal(){
    printf("Seleccione actividad de la lista:\n");
    printf("1 Crear\n");
    printf("2 Leer\n");
    printf("3 Actualizar\n");
    printf("4 Eliminar\n");
    int opt;
    printf(">");
    scanf("%d", &opt);
    return opt;
}

int main(){

    int codigo_producto;
    char maquina[256];
    int lote;
    char fecha[10];
    char hora[4];
    char encargado[256];

    int opt = menu_ppal();
    FILE *file;
    int c;
    char line[256];

    switch (opt)
    {
    case 1:
        file = fopen("produccion.txt", "a");
        printf("ingrese los datos siguientes:\n");
        printf("codigo producto: ");
        scanf("%d", &codigo_producto);
        printf("máquina: ");
        scanf("%s", maquina);
        printf("lote: ");
        scanf("%d", &lote );
        printf("fecha: ");
        scanf("%s", fecha );
        printf("hora: ");
        scanf("%s", hora );
        printf("encargado: ");
        scanf("%s",  encargado );

        fprintf(file, "%d %s %d %s %s %s\n", codigo_producto, maquina, lote, fecha, hora, encargado);
        fclose(file);
        break;
    
    case 2:
        file = fopen("produccion.txt", "r");
        while(1) {
            c = fgetc(file);
            if( feof(file) ) { 
                break ;
            }
            printf("%c", c);
        }
        fclose(file);
        break;

    case 3:
        printf("Seleccione registro a editar\n");
        file = fopen("produccion.txt", "a+");
        c=1;
        while (fgets(line, sizeof(line), file)){
            printf("%d) %s",c, line);
            c++;            
        }
        
        fclose(file);
        break;
    default:
        break;
    }

    


    return 0;
}