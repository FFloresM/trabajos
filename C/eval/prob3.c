#include <stdio.h>
int main() {
    int n, o_n, resto, resultado = 0;
    printf("ingrese numero entre 100 y 999 ");
    scanf("%d", &n);
    o_n = n;

    while (o_n != 0) {
        resto = o_n % 10;
        resultado += resto * resto * resto;
        o_n /= 10;
    }

    if (resultado == n)
        printf("%d es un numero de Armstrong.", n);
    else
        printf("%d no es un numero de Armstrong.", n);

    return 0;
}