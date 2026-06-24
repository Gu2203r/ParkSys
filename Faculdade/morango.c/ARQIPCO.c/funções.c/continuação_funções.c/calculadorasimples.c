#include <stdio.h>
#include <math.h>
#include <stdlib.h>


float somar (float num1, float num2){
  return (num1 + num2);
}

float subtrair (float num1, float num2){
  return (num1 - num2);  
}

float multiplicar (float num1, float num2){
    return (num1 * num2);
}

float dividir (float num1, float num2){
    return (num1 / num2);
}


int main(){

    float num1, num2;
    int opcao;

    system("cls");

   do {
    
    printf("Escolha uma das opcoes: 1.soma, 2.subtracao, 3.multiplicacao, 4.divisao, 5.Para sair do programa.\n");
    scanf("%d", &opcao);
    if (opcao != 5){
        printf("Digite o primeiro e o segundo numero:\n");
        scanf("%f %f", &num1, &num2); 
    }

    switch (opcao)
    {
    case 1:
        printf("O resultado da soma e:%.2f\n", somar(num1, num2));
        break;

    case 2:
        printf("O resultado da subtracao e:%.2f\n", subtrair(num1, num2));
        break;

    case 3:
        printf("O resultado da multiplicacao e:%.2f\n", multiplicar(num1, num2));
        break;

    case 4:
        printf("O resultado da divisao e:%.2f\n", dividir(num1, num2));
        break;

    case 5:
        printf("Saindo do programa...\n");
        break;
    default:
         printf("Opcao inválida! tente novamente.");
        break;
    }


   }while(opcao != 5);
    
    return 0;


}