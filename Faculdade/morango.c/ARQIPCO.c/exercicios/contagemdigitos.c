#include <stdio.h>
int main (){

    int N, numero, contagem = 0;
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);
    
    while (numero != 0) {
        contagem++;
        numero /= 10; // Remove o último dígito
    }
    
    printf("O número de dígitos é: %d\n", contagem);
    
    return 0;
}