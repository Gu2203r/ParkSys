#include <stdio.h>
#include <string.h>

int main(){

    char nome[50];
    int tamanho;

    printf("Digite seu nome:\n ");
    scanf("%s", nome);

    tamanho = strlen(nome);

    printf("%s tem %d letras\n", nome, tamanho);


    return 0;


}