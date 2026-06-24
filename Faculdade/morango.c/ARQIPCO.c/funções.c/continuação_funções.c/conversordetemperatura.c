/* Escreva um programa que converta temperaturas entre Celsius e Fahrenheit.
O programa deve solicitar ao usuário a temperatura e a unidade de medida
original, e então exibir a temperatura convertida para a outra unidade.*/


#include <stdio.h>
#include <stdlib.h>

float celsiusParaFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

 float fahrenheitParaCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}  
           
int main (){

    float celsius, fahrenheit;
    int opcao;

    system("cls"); // Limpa a tela do console (Windows)
    
    printf("Conversor de Temperatura\n");

    do{

        
         printf("Para fazer a conversao esolha uma das opcoes: 1. Celsius para Fahrenheit, 2. Fahrenheit para Celsius, 3. Para sair do programa.\n");
         scanf("%d", &opcao); // Lê a opção do usuário
        

        if(opcao != 3){
            printf("Digite a temperatura: ");
        scanf("%f", &celsius); // Lê a temperatura em Celsius
        }
        


        switch(opcao){
            case 1: 
                fahrenheit = celsiusParaFahrenheit(celsius);
                printf("Temperatura em Fahrenheit: %.2f\n", fahrenheit);
                break;
            case 2:
                fahrenheit = celsius; // A variável celsius agora contém a temperatura em Fahrenheit
                celsius = fahrenheitParaCelsius(fahrenheit);
                printf("Temperatura em Celsius: %.2f\n", celsius);
                break;
            case 3:
                 printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }       
        
    }while(opcao != 3);

}