#include <stdio.h>

int main(){

    //Estrutura de dados

    struct{

        int dia;
        int mes; // Váriaveis do tipo inteiro
        int ano;
    }x;
    x.dia = 17;
    x.mes = 6; //Valores atribuidos para as váriaveis
    x.ano = 2025;

    printf("Hoje: %d/%d/%d", x.dia, x.mes, x.ano); //Escreve a data
    


    return 0; //Indica que o programa finalizou bem.
}