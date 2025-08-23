/*Desenvolva um programa que calcule o valor futuro de um investimento com
juros compostos. O programa deve solicitar ao usuário o valor inicial do
investimento, a taxa de juros, o período de tempo e a frequência da
capitalização.*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float calcularJurosCompostos(float valorInicial, float taxaJuros, int periodo, int frequencia){
    float valorFuturo;
    // Cálculo do valor futuro com juros compostos
    valorFuturo = valorInicial * pow((1 + taxaJuros / frequencia), frequencia * periodo);
    return valorFuturo;

}

int main(){

    float valorInicial, taxaJuros, valorFuturo;
    int periodo, frequencia;
    int opcao;

    system("cls"); // Limpa a tela do console (Windows)

    do{
        

        printf("Digite o valor inicial do investimento:\n");
        scanf("%f", &valorInicial); // lê o valor inicial do investimento

        printf("Digite a taxa de juros (em decimal):\n");
        scanf("%f", &taxaJuros); // lê a taxa de juros

        printf("Digite o periodo de tempo (em anos):\n");
        scanf("%d", &periodo); // lê o período de tempo

        printf("Digite a frequencia de capitalizacao (1 - Anual, 2 - Semestral, 4 - Trimestral, 12 - Mensal):\n");
        scanf("%d", &frequencia); // lê a frequência de capitalização

        valorFuturo = calcularJurosCompostos(valorInicial, taxaJuros, periodo, frequencia); // chama a função para calcular o valor futuro
        printf("O valor futuro do investimento e: %.2f\n", valorFuturo); // exibe o valor futuro do investimento

        printf("Para sair do programa digite 0\n");

        if(opcao != 0){
            printf("Saindo do programa...\n"); // mensagem de saída do programa
        }



    }while(opcao == 0); // repete o loop até que o usuário digite 0 para sair
}