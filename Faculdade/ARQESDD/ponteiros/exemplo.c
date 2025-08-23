#include <stdio.h>

int main (){

    int numero = 50;
    int *ponteiro_numero;

    //'ponteiro_numero' agora aponta para 'numero'

    ponteiro_numero = &numero;

    printf("Valor da variavel 'numero': %d\n", numero);
    printf("Endereco da variavel 'numero': %p\n", &numero);
    printf("Valor do ponteiro 'ponteiro_numero'(endereco): %p\n", ponteiro_numero);
    printf("Valor acessado pelo ponteiro(*ponteiro_numero): %d\n", *ponteiro_numero);

    return 0;
}