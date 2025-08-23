#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_VETOR 10

void lerVetor(int vetor[]);
void somarVetores(int A[], int B[], int C[]);
void multiplicarVetores(int A[], int B[], int D[]);
void exibirVetor(char *nome_vetor, int vetor[]);


int main(){

    system("cls");

    int A [TAMANHO_VETOR];
    int B [TAMANHO_VETOR];
    int C [TAMANHO_VETOR];
    int D [TAMANHO_VETOR];

    printf("Preenchendo o vetor A \n");

    lerVetor(A);

    printf("Preenchendo o vetor B \n");

    lerVetor(B);

    somarVetores(A, B, C);

    multiplicarVetores(A, B, D);

    exibirVetor("A", A);
    exibirVetor("B", B);
    exibirVetor("C(A+B)", C);
    exibirVetor("D(A*B)", D);

    return 0;


}

void lerVetor(int vetor[]){

    printf("Digite %d numeros inteiros:\n ", TAMANHO_VETOR);

    for(int i = 0; i < TAMANHO_VETOR; i++){

        printf("Elemento %d: \n", i + 1);
        scanf("%d", &vetor[i]);
    }
}

void somarVetores(int A[], int B[], int C[]){

    for(int i = 0; i < TAMANHO_VETOR; i++){

        C[i] = A[i] + B[i];
    }
}

void multiplicarVetores(int A[], int B[], int D[]){

    for(int i = 0; i < TAMANHO_VETOR; i++){

        D[i] = A[i] * B[i];
    }
}

void exibirVetor(char *nome_vetor, int vetor[]){

    printf("Elementos do vetor %s:\n", nome_vetor);

    for(int i = 0; i < TAMANHO_VETOR; i++){

        printf("%s[%d] = %d\n", nome_vetor, i, vetor[i]);

    }


}






