//https://www.techiedelight.com/stack-implementation/

typedef struct TRANSACCION{
  int tipo;
  int monto;
}TRANSACCION;

typedef struct stack
{
	int maxsize;	// define max capacity of stack
	int top;
	TRANSACCION *transaccion;
}stack;

struct stack* crear_pila(int capacity);

int size(struct stack *pt);

// Utility function to check if the stack is empty or not
int isEmpty(struct stack *pt);

// Utility function to check if the stack is full or not
int isFull(struct stack *pt);

void push(struct stack *pt, int monto, int tipo);

TRANSACCION peek(struct stack *pt);

TRANSACCION pop(struct stack *pt);

