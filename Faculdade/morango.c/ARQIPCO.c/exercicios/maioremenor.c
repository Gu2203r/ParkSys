#include <stdio.h>

int main() {
    int N, numero, maior, menor;

    do {
        printf("Digite a quantidade de numeros (N > 0): ");
        scanf("%d", &N);

        if (N <= 0) {
            printf("Por favor, insira um valor maior que 0.\n");
        }
    } while (N <= 0);

    printf("Digite o 1o numero: ");
    scanf("%d", &numero);
    maior = menor = numero; 

    for (int i = 2; i <= N; i++) { 
        printf("Digite o %do numero: ", i);
        scanf("%d", &numero);

        if (numero > maior) {
            maior = numero;
        }
        if (numero < menor) {
            menor = numero;
        }
    }

    printf("O maior numero digitado foi: %d\n", maior);
    printf("O menor numero digitado foi: %d\n", menor);

    return 0;
}