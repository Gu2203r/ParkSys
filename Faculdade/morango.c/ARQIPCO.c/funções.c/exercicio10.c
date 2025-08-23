
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


float gerarNumeroAleatorio(int min, int max){
    srand((unsigned)time(NULL));
    return min + rand() % (max - min + 1);
}
int main(){
    int numeroJogador, numeroComputador, soma;
    char opcaoJogador[10], opcaoComputador[10];
    
    system("cls");
    
    printf("Digite um numero entre 0 e 5: ");
    scanf("%d", &numeroJogador);
    
    if (numeroJogador < 0 || numeroJogador > 5){
        printf("Numero invalido! Tente novamente.\n");
        return 1;
    }
    
    printf("Escolha Par ou Impar: ");
    scanf("%s", opcaoJogador);
    
    if (strcmp(opcaoJogador, "Par") == 0){
        strcpy(opcaoComputador, "Impar");
    } else if (strcmp(opcaoJogador, "Impar") == 0){
        strcpy(opcaoComputador, "Par");
    } else {
        printf("Opcao invalida! Tente novamente.\n");
        return 1;
    }
    
    numeroComputador = gerarNumeroAleatorio(0, 5);
    
    soma = numeroJogador + numeroComputador;
    
    printf("Numero do jogador: %d\n", numeroJogador);
    printf("Numero do computador: %d\n", numeroComputador);
    printf("Soma: %d\n", soma);
    
    if ((soma % 2 == 0 && strcmp(opcaoJogador, "Par") == 0) || (soma % 2 != 0 && strcmp(opcaoJogador, "Impar") == 0)){
        printf("Voce venceu!\n");
    } else {
        printf("Voce perdeu!\n");
    }
    
    return 0;
}


