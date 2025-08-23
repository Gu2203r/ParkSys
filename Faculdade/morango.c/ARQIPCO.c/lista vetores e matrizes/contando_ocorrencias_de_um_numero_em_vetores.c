#include <stdio.h> 

#define TAMANHO_VETOR 8 // Define uma constante para o tamanho do vetor


//Função que conta as ocorrências do número
int contarOcorrencias(int vetor[], int tamanho, int numero_alvo);



int main() {
    int meuVetor[TAMANHO_VETOR]; // Declara um vetor de 8 inteiros
    int numeroProcurado;         // Variável para armazenar o número que o usuário quer procurar
    int ocorrencias;             // Variável para armazenar o resultado da contagem

    printf("Preenchimento do Vetor\n");
    printf("Por favor, digite %d numeros inteiros:\n", TAMANHO_VETOR);

    
    for (int i = 0; i < TAMANHO_VETOR; i++) {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &meuVetor[i]);
    }

    printf("Busca no Vetor\n");
    printf("Qual numero voce gostaria de procurar no vetor? ");
    scanf("%d", &numeroProcurado); 

    // Chama a função para contar as ocorrências do número
    ocorrencias = contarOcorrencias(meuVetor, TAMANHO_VETOR, numeroProcurado);

    printf("Resultado da Busca\n");
    
    printf("O numero %d aparece %d vez(es) no vetor.\n", numeroProcurado, ocorrencias);

    return 0; 
}

int contarOcorrencias(int vetor[], int tamanho, int numero_alvo) {
    int contador = 0; 

    
    for (int i = 0; i < tamanho; i++) {
        
        if (vetor[i] == numero_alvo) {
            contador++;
        }
    }
    return contador; // Retorna o total de vezes que o número apareceu
}