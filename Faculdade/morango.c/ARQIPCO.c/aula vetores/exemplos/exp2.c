#include <stdio.h> //biblioteca com comandos de escrita

int main(){

    int vetor[5]; // vetor de numeros inteiros
    int i ; // indice : indica uma posição do conjunto

    // preenchimento automático do conjunto
    
    for(i = 0; i < 5; i++){

        printf("\n Valor [%d] : ", i);
        scanf("%d", &vetor[i]);

        
    }

    //exibição do elementos do conjunto

    printf("Dados armazenados no conjunto \n [");

    for(i = 0; i < 5; i++){

        printf(" %d ", vetor[i]);

    }

    printf("]\n");

    //finaliza o programa

    return 0;



}
