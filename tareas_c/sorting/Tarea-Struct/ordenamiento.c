#include <stdio.h>
#include <stdlib.h>
#include "ordenamiento.h"
#include "redes.h"

void print(int *arr) {
  int l = numero_nodos;
  for(int i = 0; i < l; i++)
    printf("%d\n", arr[i]);
  printf("--------\n");
}

//Para debbuging
/*
int num_debbug = 1;
void debbug() {
  printf("---state %d---\n", num_debbug);
  num_debbug++;
}
*/

void guardar_nodos_ordenados(char *filename)
{
  temp = malloc(numero_nodos*sizeof(int));
  indexs = malloc(numero_nodos*sizeof(int));

  //Para limpiar el archivo si es que existe
  FILE *fp;
  fp = fopen(filename, "w");
  fclose(fp);

  //Bubblesort
  temp_init(temp);
  order_metod = "Bubblesort";
  bubbleSort(temp, numero_nodos);
  print_in_text(filename,indexs);
  //Mergesort
  temp_init(temp);
  order_metod = "Mergesort";
  mergeSort(temp, 0, numero_nodos-1);
  print_in_text(filename,indexs);
  //Quicksort
  temp_init(temp);
  order_metod = "Quicksort";
  quickSort(temp, 0, numero_nodos - 1);
  print_in_text(filename,indexs);
  //Selectionsort
  temp_init(temp);
  order_metod = "Selectionsort";
  selectionSort(temp, numero_nodos);
  print_in_text(filename,indexs);
  //Insertionsort
  temp_init(temp);
  order_metod = "Insertionsort";
  insertionSort(temp, numero_nodos);
  print_in_text(filename,indexs);
}

//Reinicia el arreglo temporal al estado inicial y limpia las demas variables
void temp_init(int *temp)
{
  for (int i = 0; i < numero_nodos; i++)
  {
    //copia el numero de links
    temp[i] = nodo[i].links;
    //guarda el link del id
    indexs[i] = i;
  }
  asign = 0;
  comp = 0;
}

void print_in_text(char *filename, int *arr)
{
  FILE *fp;
  fp = fopen(filename, "a");
  for (int i = 0; i < numero_nodos; i++)
    fprintf(fp, "%d ", arr[i]);
  fprintf(fp, "\n--\n");
  fprintf(fp, "Algoritmo: %s\n", order_metod);
  fprintf(fp, "Asignaciones: %d\n", asign);
  fprintf(fp, "Comparaciones: %d\n-------------------\n", comp);
  fclose(fp);
}

//para hacer swaps
void swap(int *a, int *b, int ia, int ib)
{
  int t = *a;
  *a = *b;
  *b = t;
  int i = indexs[ia];
  indexs[ia] = indexs[ib];
  indexs[ib] = i;

  asign++;
}

//Bubblesort
void bubbleSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++) {
      comp++;
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1], j, j + 1);
      }
    }
  }
}

//Mergesort
void merge(int arr[], int l, int m, int r)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];
  int Li[n1], Ri[n2];

  for (i = 0; i < n1; i++) {
    L[i] = arr[l + i];
    Li[i] = indexs[l + i];
  }
    
  for (j = 0; j < n2; j++) {
    R[j] = arr[m + 1 + j];
    Ri[j] = indexs[m + 1 + j];
  }
    
  i = 0; 
  j = 0; 
  k = l; 
  while (i < n1 && j < n2)
  {
    comp++;
    asign++;
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      indexs[k] = Li[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      indexs[k] = Ri[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    asign++;
    arr[k] = L[i];
    indexs[k] = Li[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    asign++;
    arr[k] = R[j];
    indexs[k] = Ri[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

//Quicksort
int partition(int arr[], int low, int high)
{
  int pivot = arr[high]; 
  int i = (low - 1);     

  for (int j = low; j <= high - 1; j++)
  {
    comp++;
    if (arr[j] < pivot)
    {
      i++; 
      swap(&arr[i], &arr[j], i, j);
    }
  }
  swap(&arr[i + 1], &arr[high], i + 1, high);
  return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}
//Selectionsort
void selectionSort(int arr[], int n)
{
  int i, j, min_idx;

  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++) {
      comp++;
      if (arr[j] < arr[min_idx])
        min_idx = j;
    }
    if(min_idx != i)
      swap(&arr[min_idx], &arr[i], min_idx, i);
  }
}

//Insertionsort
void insertionSort(int arr[], int n)
{
  int i, key, keyindexs, j;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    keyindexs = indexs[i];
    j = i - 1;

    while (j >= 0 && arrVsKey(arr[j], key))
    {
      asign++;
      arr[j + 1] = arr[j];
      indexs[j + 1] = indexs[j];
      j = j - 1;
    }
    asign++;
    arr[j + 1] = key;
    indexs[j + 1] = keyindexs;
  }
}
/*
Si se pusiera comp++; dentro del while, no se agregaría la comparacion en caso de que arr>key ya que se detendría el ciclo
*/
int arrVsKey(int x, int y)
{
  comp++;
  if(x>y)
    return 1;
  else
    return 0;
}