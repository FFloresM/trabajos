#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct fila_atencion{
	int numero;
	char tipo_paciente[3];
	struct fila_atencion *sgte;
};

void orden_de_atencion(struct fila_atencion *ATE, struct fila_atencion *AG){

    struct fila_atencion *aux1= ATE;
    struct fila_atencion *aux2= AG;
    int contador=0;

    while (aux1->sgte != NULL && aux2->sgte!=NULL)
    {
        if (strcmp(aux1->tipo_paciente,"ATE"))
        {
            printf("%d",aux1->numero);
            contador++;
            aux1 = Eliminar(ATE);

        }
        if (contador % 2==0)
        {
            if (strcmp(aux2->tipo_paciente,"AG"))
            {
                printf("%d",aux2->numero);
                aux2 = Eliminar(AG);

            }
        }
         
        
    }
     
}