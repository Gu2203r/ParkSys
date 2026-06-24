#include <stdio.h>
int main(){
    int numeros_pares = 2;
    int soma = 0;
    int i = 0;
    int n = 0;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Número inválido. Por favor, insira um número inteiro positivo.\n");
        return 1;
    }
    printf("Os %d primeiros números pares são:\n", n);
    for (i = 0; i < n; i++) {
        printf("%d ", numeros_pares);
        soma += numeros_pares;
        numeros_pares += 2;
    }
    printf("\nA soma dos %d primeiros números pares é: %d\n", n, soma);
    return 0;
}










