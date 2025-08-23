#include <stdio.h>
int main() {


int numero, soma = 0, contador = 0;
    float media;

    printf("Digite uma sequencia de numeros para calcular a media aritmetica.\n");
    printf("Digite -1 para encerrar.\n");

    do {
        printf("Digite um numero: ");
        scanf("%d", &numero);

        if (numero != -1) {
            soma += numero; 
            contador++;     
        }
    } while (numero != -1); 

    if (contador > 0) {
        media = (float)soma / contador; 
        printf("A media aritmetica e: %.2f\n", media);
    } else {
        printf("Nenhum numero valido foi digitado.\n");
    }

    return 0;
}