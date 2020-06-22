#include "pila.h"
#include <stdlib.h>
#include <stdio.h>

// Utility function to initialize stack
struct stack* crear_pila(int capacity)
{
	stack *pt = (struct stack*)malloc(sizeof(struct stack));

	pt->maxsize = capacity;
	pt->top = -1;
	pt->transaccion = malloc(sizeof(TRANSACCION) * capacity);

	return pt;
}

// Utility function to return the size of the stack
int size(struct stack *pt)
{
	return pt->top + 1;
}

// Utility function to check if the stack is empty or not
int isEmpty(struct stack *pt)
{
	return pt->top == -1;	// or return size(pt) == 0;
}

// Utility function to check if the stack is full or not
int isFull(struct stack *pt)
{
	return pt->top == pt->maxsize - 1;	// or return size(pt) == pt->maxsize;
}

// Utility function to add an element x in the stack
void push(struct stack *pt, int monto, int tipo) //INSERTAR
{
	// check if stack is already full. Then inserting an element would
	// lead to stack overflow
	if (isFull(pt))
	{
		printf("OverFlow\nProgram Terminated\n");
		exit(EXIT_FAILURE);
	}

	//printf("Inserting %d\n", monto);
  pt->top++;
  pt->transaccion[pt->top].monto = monto;
  pt->transaccion[pt->top].tipo = tipo;
}

// Utility function to return top element in a stack
TRANSACCION peek(struct stack *pt)
{
	TRANSACCION t;
  t.monto = 0;
  t.tipo = 0;
  // check for empty stack
	if (!isEmpty(pt))
    //arreglo[0] = pt->transaccion[pt->top].tipo;
    //arreglo[1] = pt->transaccion[pt->top].tipo;
    return pt->transaccion[pt->top];
	else
		return t;
}

// Utility function to pop top element from the stack
TRANSACCION pop(struct stack *pt)
{
	// check for stack underflow
	if (!isEmpty(pt))
	{
    //printf("Removing %d\n", peek(pt).monto);

    return pt->transaccion[pt->top--]; 
   //printf("UnderFlow\nProgram Terminated\n");
		//exit(EXIT_FAILURE);
	} else {
    return *pt->transaccion;
  }

	// decrease stack size by 1 and (optionally) return the popped element
	return pt->transaccion[pt->top--];
}


