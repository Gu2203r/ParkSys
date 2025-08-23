#include <stdio.h>

int main(){

    int valor = 100;
    int *p_valor;

    p_valor = &valor;

    printf("Valor antes da mudanca: %d\n", valor); //100

    //USamos o ponteiro para mudar o valor da variavel 'valor' 

    *p_valor = 200;

    printf("Valor depois da mudanca: %d\n", valor); //200
    printf("Valor acessado pelo ponteiro: %d\n", *p_valor); //200

    return 0;
}