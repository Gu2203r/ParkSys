#include <stdio.h> //biblioteca com comandos de escrita


void imprimirVetor (int vetor []);
void imprimirVetorInv(int vetor[]);



int main(){

    int vetor[5]; // vetor de numeros inteiros
    int i ; // indice : indica uma posição do conjunto

    // usuario preenche o conjunto
    
    for(i = 0; i < 5; i++){

        printf("\n Valor [%d] : ", i);
        scanf("%d", &vetor[i]);

        
    }

    //exibição do elementos do conjunto

    imprimirVetor( vetor);

    
    //exibição do elementos do conjunto
    //em ordem inversa

    imprimirVetorInv (vetor);




    //finaliza o programa

    return 0;



}

void imprimirVetor (int vetor []){
    int i;

    for(i = 0; i < 5; i++){

        printf(" %d ", vetor[i]);

}

printf("]\n");

}


void imprimirVetorInv (int vetor []){

    int i;

    printf("Dados armazenados no conjunto \n ");

    for(i = 4; i >= 0; i--){

        printf(" %d ", vetor[i]);

}
printf("]\n");

}





