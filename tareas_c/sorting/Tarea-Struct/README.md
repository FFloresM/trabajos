# Tarea 1
Integrantes:
  * Andre Thierry
  * Cristobal Paredes

## Documentación

El programa funciona de la siguiente forma

...
`printf("Comienzo de lectura...\n");`
`leer_archivo("NSFnet.txt");` : empieza a correr redes.c
`printf("Fin de la lectura...\n");`
`printf("Inicio de ordenamiento...\n");`
`guardar_nodos_ordenados("out.txt");` : empieza a correr ordenamiento.c
`printf("Listo...\n");`
...

`leer_archivo()` lee un archivo que **debe** de existir o sino no funciona
`guardar_nodos_ordenados()` crea un archivo de salida con los numero de links ordenados

### redes.h

`void leer_archivo(char* filename)`

Declaración de la función principal que lee el archivo:

`int numero_nodos`

Guarda el numero de nodos total que hay en el archivo

`int numero_links`

Guarda el numero de links total que hay en el archivo

`typedef struct Nodo {`
  `int id;`
  `int *link_ids;`
  `int links;`
`} Nodo;`

`Nodo *nodo;`

Declaración del struct y la dirección donde se guardara la dirección de memoria del arreglo de nodos

### redes.c

**Linea 8-18**

Lectura de la cabezera del archivo, los fgets() se saltan los elementos de diseño

**Linea 20**

Alocación de memoria dinamica de `nodo`en base a `numero_nodos`

**Linea 22**

Matriz que guardara el arreglo de los id de los links segun nodo, alocación estatica, el mayor numero de links ides que puede guardar un nodo son el total de ides, por eso `numero_nodos`*`numero_links`, previniendo que ocurra un overflow de algun arreglo de un nodo

**Linea 24-29**

Asumiendo que el id de los nodos van de 0 a `numero_nodos-1`, sin saltarse ninguno, se llena los id de todos los nodos. 

`nodo[i].link_ids = links_matrix[i]`

Aca se les asignado a cada `nodo[i].link_ids` la dirección de memoria de `links_matrix[i]` que le corresponde segun su orden, de esta manera cuando se llene `links_matrix`, `nodo[i].link_ids`  accedera a su propio arreglo de link ids que le corresponde

`nodo[i].links = 0`

Inicializa el numero de links de cada nodo en 0

**Linea 32-47**

Lectura del archivo para luego guardar los datos en los nodos

`int source;`

`int dest;` (Este no se utiliza la verda)

`int hops;`

`int link_id;`

Variables que coresponden a cada campo del archivo, `fscanf(fp, "[%d]\t[%d]\t%d\t%s\n", &source, &dest, &hops, buff)` asigna cada campo a las variables

`if(hops > 1){` -> 

​      `continue;`

si tiene más de uno se salta al proximo ciclo del `for()`

​    `}else{`

En caso contrario se procede a evaluar las variables del nodo `source`

​      `link_id = atoi(buff);`

​      `nodo[source].link_ids[nodo[source].links]= link_id;`

se guarda el link_id segun el nodo que corresponda (`source`) y el ultimo indice vacio del arreglo correspondiente (por eso `nodo[source].links`), si habian 0, se llena en `nodo[source].link_ids[0]` y ...

​      `nodo[source].links += 1;`

... se suma 1 al numero de links del nodo, puesto que se agrego un link, por lo tanto el proximo indice vacio sera 1 en `nodo[source].link_ids`, lo que a la ves significa que el nodo tiene 1 link. (`nodo[source].links`== 1)

**Linea 51**

Cierre del archivo

### ordenamiento.h

`//Funciones`

`void guardar_nodos_ordenados(char *filename);` : Función principal

`void print_in_text(char *filename, int *arr);` : Imprime en el archivo de salida 

`void temp_init(int *temp);` : Reinicia los valores de una variable temporal

`void swap(int *a, int *b, int ia, int ib);` : Swap de direcciones, `int ia` e `int ib` es para hacer swap de indices

`void print(int *arr);` : función para imprimir en pantall, no se utiliza

**Funciones de ordenamiento**

`//Bubblesort`

`void bubbleSort(int arr[], int n);`

`//Mergesort`

`void merge(int arr[], int l, int m, int r);`

`void mergeSort(int arr[], int l, int r);`

`//Quicksort`

`int partition(int arr[], int low, int high);`

`void quickSort(int arr[], int low, int high);`

`//Selectionsort`

`void selectionSort(int arr[], int n);`

`//Insertionsort`

`void insertionSort(int arr[], int n);`

`int arrVsKey(int x, int y);` : funcion creada para no perder una iteración de comparacion en el algoritmo, mas informacion in-code.

NOTA: Cada vez que se hace alguna comparacion de la forma <(=) o >(=), `comp` se incrementa una vez. El mismo caso para asign cuando ocurre un `swap()` o una asignacion de variable a alguna direccion del arreglo `temp`. Luego de imprimir en el archivo se utiliza `temp_init()` para reiniciar todo y seguir con el siguiente algoritmo.

`//Variables globales`

`int asign, comp;`	:  `asign` cuenta las asignaciones hechas, `comp` las comparaciones

`char *order_metod;` : buffer que guarda el nombre del odenamiento en uso

`int *temp;` : direccion temporal de el numero de links de cada nodo a ordenar

`int *indexs;` : indices de la variable temporal, tambien se ordenan segun lo anterior y es lo que se imprime en el archivo

### ordenamiento.c

**void guardar_nodos_ordenados(char *filename)**

`temp = malloc(numero_nodos*sizeof(int));`

 `indexs = malloc(numero_nodos*sizeof(int));`

Alocación de memoria

`FILE *fp;`

`fp = fopen(filename, "w");`

`close(fp);`

Limpieza del archivo si es que ya existe

//*ordenamiento*

  temp_init(temp);	Asignación de los valores del struct nodo a variable `temp`, se vuelve a llamar para reordenarlos a la posición original unto con `indexs`, reinicio de `asign` y `comp`.

  order_metod = "*ordenamiento*";	

  *func_*ordenamiento(temp, numero_nodos); funcion correspondiente al algoritmo de ordenamiento

  print_in_text(filename,indexs); Escribe en el archivo de salida

