#include <stdio.h>
int main(){
    int N = 0;
    int soma = 0;
   
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &N);

    if (N < 0) {
        printf("Por favor, insira um numero positivo.\n");
        return 1;

    }

    while( N > 0){
        int digito = N % 10; 
        if( digito % 2 == 0){
            soma += digito;
        }
        N /= 10; 

        printf("Soma dos digitos pares: %d\n", soma);
    }


    return 0;
}