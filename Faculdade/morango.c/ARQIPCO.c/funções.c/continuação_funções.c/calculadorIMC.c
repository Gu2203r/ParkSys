/*Escreva um programa que calcule o Índice de Massa Corporal (IMC) de uma
pessoa. O programa deve solicitar ao usuário o peso em quilogramas e a
altura em metros, calcular o IMC e exibir a classicação do IMC (e.g., "Abaixo
do peso", "Peso normal", "Sobrepeso", etc.).*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calcularIMC(float peso, float altura) {
    return peso / (altura * altura); // Calcula o IMC
}

int main(){
    float peso, altura, imc;
    int opcao;

    system("cls"); // Limpa a tela do console (Windows)

    printf("Calculadora de IMC\n");
    printf("Para sair digite 1.\n");

    do{
        printf("Digite seu peso em kg: ");
        scanf("%f", &peso); // Lê o peso do usuário
        printf("Digite sua altura em metros: ");
        scanf("%f", &altura); // Lê a altura do usuário

        imc = calcularIMC(peso, altura); // Chama a função para calcular o IMC

        printf("Seu IMC e: %.2f\n", imc); // Exibe o IMC calculado

        if(imc < 18.5){
            printf("Abaixo do peso\n");
        }else if(imc >= 18.5 && imc < 24.9){
            printf("Peso normal\n");
        }else if(imc >= 25 && imc < 29.9){
            printf("Sobrepeso\n");
        }else{
            printf("Obesidade\n");
        }

        if(opcao == 1){
            printf("Saindo do programa...\n");
            break; // Sai do loop se o usuário digitar 1
        }
    }while(opcao != 1); // Repete até o usuário digitar 1

    return 0;
}