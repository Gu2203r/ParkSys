#include <stdio.h>
int main(){
    int N, i = 1;
    double soma = 0.0;

    printf("Para calcular a serie de fracoes voce precisa fornecer um numero inteiro positivo\n");
    printf("1/1 + 1/2 + 1/3 + 1/4 + 1/N\n");
    printf("Digite um numero para completar a serie de fracoes : \n");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Por favor, insira um numero inteiro positivo.\n");
        return 1;
    }

    while (i <= N) {
        soma += 1.0 / i; 
        i++;             
    }

    printf("A soma da serie e: %.6f\n", soma);


    

return 0;



}