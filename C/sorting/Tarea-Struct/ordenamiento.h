//#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funciones
void guardar_nodos_ordenados(char *filename);
void print_in_text(char *filename, int *arr);
void temp_init(int *temp);
void swap(int *a, int *b, int ia, int ib);
void print(int *arr);

//Bubblesort
void bubbleSort(int arr[], int n);
//Mergesort
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
//Quicksort
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
//Selectionsort
void selectionSort(int arr[], int n);
//Insertionsort
void insertionSort(int arr[], int n);
int arrVsKey(int x, int y);

//Variables globales
int asign, comp;
char *order_metod;
int *temp;
int *indexs;
