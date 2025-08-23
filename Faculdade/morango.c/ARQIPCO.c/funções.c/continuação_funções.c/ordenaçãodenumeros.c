/*Escreva um programa que solicite ao usuário uma lista de números e os
ordene em ordem crescente ou decrescente. Você pode usar algoritmos de
ordenação como bubble sort, selection sort ou insertion sort.:*/


#include <stdio.h>
#include <stdlib.h>


int ordenarNumeros(int numeros[], int tamanho, int ordem) {
    int i, j, temp;
    if (ordem == 1) { // Ordem crescente
        for (i = 0; i < tamanho - 1; i++) {
            for (j = 0; j < tamanho - i - 1; j++) {
                if (numeros[j] > numeros[j + 1]) {
                    temp = numeros[j];
                    numeros[j] = numeros[j + 1];
                    numeros[j + 1] = temp;
                }
            }
        }
    } else { // Ordem decrescente
        for (i = 0; i < tamanho - 1; i++) {
            for (j = 0; j < tamanho - i - 1; j++) {
                if (numeros[j] < numeros[j + 1]) {
                    temp = numeros[j];
                    numeros[j] = numeros[j + 1];
                    numeros[j + 1] = temp;
                }
            }
        }
    }
    return 0;
}
int main() {
    int numeros[100], tamanho, i, ordem;
    char opcao;
    
    system("cls"); // Limpa a tela do console (Windows)
    
    do{

        printf("Digite o tamanho da lista de numeros: ");
    scanf("%d", &tamanho); // Lê o tamanho da lista
    
    printf("Digite os numeros:\n");
    for (i = 0; i < tamanho; i++) {
        scanf("%d", &numeros[i]); // Lê os números da lista
    }
    
    printf("Escolha a ordem de ordenacao (1 - Crescente, 2 - Decrescente): ");
    scanf("%d", &ordem); // Lê a ordem de ordenação
    
    ordenarNumeros(numeros, tamanho, ordem); // Chama a função para ordenar os números
    
    printf("Lista ordenada:\n");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", numeros[i]); // Exibe a lista ordenada
    }
    
    }while(opcao != 'n'); // Repete até o usuário digitar 'n'


    
    return 0;
}
