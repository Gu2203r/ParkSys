#include <stdio.h>
#include "funcao.c"

int main(){

    int num1, num2;
    printf("\n Digite o numero 1:");
    scanf("%d", &num1);
    printf("\n Digite o numero 2:");
    scanf("%d", &num2);
    printf("A soma = %d\n", soma(num1, num2));
    printf("A multiplicacao = %d\n", multi(num1, num2) );
    
    return 0;
}

