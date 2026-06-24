#include <stdio.h>
#include "data.c"

#define TAM_NOME 30

typedef struct{

    char nome [TAM_NOME];
    Data dataDeNascimento;
    char email[TAM_NOME];
} Contato;

int main(){

    Contato contato;

    printf("\n Digite seu nome :");

    gets(contato.nome);
    


}

