#include <stdio.h> //biblioteca com comandos de escrita

int main(){

    int vetor[5]; // vetor de numeros inteiros
    int i ; // indice : indica uma posição do conjunto

    // preenchimento automático do conjunto
    
    vetor[0] = 0;
    vetor[1] = 10;
    vetor[2] = 20;
    vetor[3] = 30;
    vetor[4] = 40;

    //exibição do elementos do conjunto

    for(i = 0; i < 5; i++){
        printf("%d", vetor[i]);

    }

    printf("]\n");

    //finaliza o programa

    return 0;



}
