#include <stdio.h>

int menu_ppal(){
    printf("Seleccione actividad de la lista:\n");
    printf("1 Crear\n");
    printf("2 Leer\n");
    printf("3 Actualizar\n");
    printf("4 Eliminar\n");
    printf("0 Salir\n");
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

    int opt;
    FILE *file, *ftemp;
    int c, count;
    char line[256];

    while(opt != 0)
        opt = menu_ppal();
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
            file = fopen("produccion.txt", "r");
            c=1;
            while (fgets(line, sizeof(line), file)){
                printf("%d) %s",c, line);
                c++;            
            }
            rewind(file); //volver al inicio del archivo
            printf(">");
            scanf("%d", &c);
            ftemp = fopen("replace.tmp", "w");
            count = 0;
            printf("ingrese los nuevos datos\n");
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
            while ((fgets(line, sizeof(line), file)) != NULL){
                count++;
                if (count == c)
                    fprintf(ftemp, "%d %s %d %s %s %s\n", codigo_producto, maquina, lote, fecha, hora, encargado);
                else
                    fprintf(ftemp,"%s", line);
                    printf("%s", line);
            }
            fclose(ftemp);
            fclose(file);
            remove("produccion.txt");
            rename("replace.tmp", "produccion.txt");
            break;
        
        case 4:
            printf("Seleccione registro a eliminar\n");
            file = fopen("produccion.txt", "r");
            c=1;
            while (fgets(line, sizeof(line), file)){
                printf("%d) %s",c, line);
                c++;            
            }
            rewind(file); //volver al inicio del archivo
            printf(">");
            scanf("%d", &c);
            ftemp = fopen("replace.tmp", "w");
            count = 0;
            while ((fgets(line, sizeof(line), file)) != NULL){
                count++;
                if(count != c)
                    fputs(line, ftemp);
            }
            fclose(ftemp);
            fclose(file);
            remove("produccion.txt");
            rename("replace.tmp", "produccion.txt");
            break;
        default:
            printf("ingrese una opción correcta\n");
            break;
        }

    


    return 0;
}