

#include <stdio.h>
#include <math.h>

float multiplicacao(float a, float b){
    float resultado = 0;
    for(int i = 0; i < b; i++){
        resultado += a;
    }
    return resultado;
}
float divisao(float a, float b){
    float resultado = 0;
    while(a >= b){
        a -= b;
        resultado++;
    }
    return resultado;
}

int main(){
    float a, b, resultadoMultiplicacao, resultadoDivisao;
    int opcao;

    system("cls");  

    printf("Escolha a operacao:\n1. Multiplicacao\n2. Divisao\n");
    scanf("%d", &opcao);
    printf("Digite o primeiro numero: ");
    scanf("%f", &a);
    printf("Digite o segundo numero: ");
    scanf("%f", &b);

    resultadoMultiplicacao = multiplicacao(a, b);
    resultadoDivisao = divisao(a, b);   

    if(opcao == 1){
        printf("Resultado da multiplicacao: %.2f\n", resultadoMultiplicacao);
    } else if(opcao == 2){
        printf("Resultado da divisao: %.2f\n", resultadoDivisao);
    } else {
        printf("Opcao invalida!\n");
    }
    return 0;
}