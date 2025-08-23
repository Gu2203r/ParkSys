#include <stdio.h>

int main() {
    int numero, soma;

    do {
        soma = 0; 
        printf("Digite um numero inteiro positivo (ou 0 para sair): ");
        scanf("%d", &numero);

        if (numero < 0) {
            printf("Por favor, insira um numero positivo.\n");
        }
        for (int temp = numero; temp > 0; temp /= 10) {
            soma += temp % 10; 
        }

        if (numero > 0) {
            printf("A soma dos digitos de %d e: %d\n", numero, soma);
        }

    } while (numero != 0); 

    printf("Programa encerrado.\n");
    return 0;
}


