#include "prueba.h"

void leer_archivo(char* filename){
    FILE *f = fopen(filename,"r");
    int id;
    char* nombre;
    char* apellido;
    char* email;
    char* genero;
    float altura;
    char aux[1000];

    fgets(aux,999,f);
    cantidad_de_personas = atoi(aux);
    personas = malloc(cantidad_de_personas*sizeof(struct p));

    fgets(aux,999,f);

    int count = 0;
    while(fgets(aux,999,f)){
        id = atoi(strtok(aux,"\t"));
        nombre = strtok(NULL,"\t");
        apellido = strtok(NULL,"\t");
        email = strtok(NULL,"\t");
        genero = strtok(NULL,"\t");
        altura = atof(strtok(NULL,"\t"));

        personas[count].id = id;
        strcpy(personas[count].nombre,nombre);
        strcpy(personas[count].apellido,apellido);
        strcpy(personas[count].email,email);
        strcpy(personas[count].genero,genero);
        personas[count].altura = altura;
        count++;
    }
}

void ordenar(void){

    int i = 0, j = 0, tmpID;
    float tmpAltura;
    char* tmpnombre, tmpApellido,tmpEmail, tmpGenero;
    for (i = 0; i < cantidad_de_personas; i++) {   // loop n times - 1 per elemet
        
        for (j = 0; j < cantidad_de_personas - i -1; j++) { // last i elements are sorted already
            if (personas[j].altura > personas[j + 1].altura) {  // swop if order is broken
                tmpAltura = personas[j].altura;
                tmpnombre = personas[j].nombre;
                tmpApellido = *personas[j].apellido;
                tmpEmail = *personas[j].email;
                tmpGenero = *personas[j].genero;
                tmpID = personas[j].id;


                personas[j].altura = personas[j+1].altura;
                *personas[j].genero = *personas[j + 1].genero;
                *personas[j].nombre = *personas[j+1].nombre;
                *personas[j].apellido = *personas[j+1].apellido;
                *personas[j].email = *personas[j+1].email;
                personas[j].id = personas[j+1].id;


                  personas[j + 1].altura = tmpAltura;
                 *personas[j + 1].nombre = *tmpnombre;
                  *personas[j + 1].apellido = tmpApellido;
                  *personas[j + 1].email = tmpEmail;
                  *personas[j + 1].genero = tmpGenero;
                 personas[j + 1].id = tmpID;



            }
        }
    }


    for (i = 0; i < cantidad_de_personas; i++) {   // loop n times - 1 per elemet
        
        for (j = 0; j < cantidad_de_personas - i -1; j++) { // last i elements are sorted already
            if (strcmp(personas[j].genero,personas[j + 1].genero)) {  // swop if order is broken
                tmpAltura = personas[j].altura;
                tmpnombre = personas[j].nombre;
                tmpApellido = *personas[j].apellido;
                tmpEmail = *personas[j].email;
                tmpGenero = *personas[j].genero;
                tmpID = personas[j].id;


                personas[j].altura = personas[j+1].altura;
                *personas[j].genero = *personas[j + 1].genero;
                *personas[j].nombre = *personas[j+1].nombre;
                *personas[j].apellido = *personas[j+1].apellido;
                *personas[j].email = *personas[j+1].email;
                personas[j].id = personas[j+1].id;


                  personas[j + 1].altura = tmpAltura;
                 *personas[j + 1].nombre = *tmpnombre;
                  *personas[j + 1].apellido = tmpApellido;
                  *personas[j + 1].email = tmpEmail;
                  *personas[j + 1].genero = tmpGenero;
                 personas[j + 1].id = tmpID;



            }
        }
    }



}



void imprimir(int posicion){
    printf("ID: %i\n%s %s\n%s\n%s\n%f\n\n",personas[posicion].id,personas[posicion].nombre,personas[posicion].apellido,personas[posicion].email,personas[posicion].genero,personas[posicion].altura);
}

void imprimir_personas()
{
    for(int i = 0; i < cantidad_de_personas; i++){
        printf("ID: %i\n%s %s\n%s\n%s\n%f\n\n",personas[i].id,personas[i].nombre,personas[i].apellido,personas[i].email,personas[i].genero,personas[i].altura);
    }
}

void swap(struct p *a, struct p *b){
    struct p tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
