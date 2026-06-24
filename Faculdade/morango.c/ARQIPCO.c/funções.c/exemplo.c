#include <stdio.h>
#include <stdlib.h>
/* programa para ler dois numeros inteiros, diferentes entre si, e exibir o maior deles*/


int maiorInteiro(int numero1, int numero2){
    if (numero1 > numero2) return (numero1);
    else return (numero2);
}

int main(){

    // variaveis para armazenar os numeros digitados

    int numero1, numero2 ;

    system ("cls");
    
    
    // entrada de dados

    printf("Digite o numero1:");
    scanf("%d", &numero1);
    printf("Digite o numero2:");
    scanf("%d", &numero2);


    //saida

    printf("O maior valor = %d", maiorInteiro (numero1, numero2));

    return 0;






}