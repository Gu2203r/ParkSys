#include <stdio.h>
#include <string.h>

int main(){

    char nome[50];
    char nome_copia[50];

    printf("Digite o seu nome\n");
    scanf("%s", nome);

    strcpy (nome_copia, nome);

    printf("Ola, %s",nome_copia);

    return 0 ;

}