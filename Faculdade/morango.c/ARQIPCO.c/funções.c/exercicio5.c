
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


float RealToDolar(float valor){
    const float cotacao_dolar = 5.70;
    return valor / cotacao_dolar;
}
float DolarToReal(float valor){
    const float cotacao_dolar = 5.70;
    return valor * cotacao_dolar;
}



int main(){
    float valor, resultado;
    int opcao;
    
    
    system("cls");
    
    printf("Escolha a conversao:\n1. Real para Dolar\n2. Dolar para Real\n");
    scanf("%d", &opcao);
    
    if(opcao == 1){
        printf("Digite o valor em reais: ");
        scanf("%f", &valor);
        resultado = RealToDolar(valor);
        printf("O valor em dolares e: %.2f\n", resultado);
    } else if(opcao == 2){
        printf("Digite o valor em dolares: ");
        scanf("%f", &valor);
        resultado = DolarToReal(valor);
        printf("O valor em reais e: %.2f\n", resultado);
    } else {
        printf("Opcao invalida!\n");
    }
    
    return 0;
}