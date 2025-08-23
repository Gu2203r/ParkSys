/*Desenvolva um jogo em que o computador gera um número aleatório e o
usuário tenta adivinhar qual é esse número. O programa deve fornecer dicas
ao usuário, como "o número é maior" ou "o número é menor", até que o
usuário acerte*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numeroAleatorio(int min, int max){
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    return (rand() % (max - min + 1)) + min; // Gera um número aleatório entre min e max
}
              
int main(){

    int numero = 60; // numeroAleatorio(min, max);
    int tentativa;
    int opcao;
    
    system("cls"); // Limpa a tela do console (Windows)
    printf("Bem-vindo ao jogo de adivinhacao!\n");
    printf("Digite 0 para sair do programa.\n");

    do{
        printf("Digite um numero entre 1 e 100:\n");
        scanf("%d", &tentativa); // Lê a tentativa do usuário

        if(opcao != 0){
            printf("Saindo do programa...\n");
        }
        if(tentativa < numero){
            printf("O numero eh maior que %d\n", tentativa); // Dica: o número é maior
        }else if(tentativa > numero){
            printf("O numero eh menor que %d\n", tentativa); // Dica: o número é menor
        }else{
            printf("Parabens! Voce acertou o numero %d!\n", numero); // O usuário acertou
        }

    }while(tentativa != numero); // Repete até o usuário acertar o número
    return 0;

}