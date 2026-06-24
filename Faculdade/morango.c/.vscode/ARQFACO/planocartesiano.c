#include <stdio.h>

int main(){

    int x, y, opcao;

    system("cls");
    

    do{

        printf("Digite o valor de x\n");
        scanf("%d", &x);
    
        printf("Digite o valor de y\n");
        scanf("%d", &y);


        if((x > 0) && (y > 0)){

            printf("Primeiro\n");

        }else if((x < 0) && (y > 0)){

            printf("Segundo\n");


        }else if((x < 0) && (y < 0)){

            printf("Terceiro\n");

        }else if((x > 0) && (y < 0)){

            printf("Quarto\n");
        }

        printf("Deseja continuar? 1.sim, 2.nao\n");
        scanf("%d", &opcao);


    }while(opcao != 2);

    return 0;

}