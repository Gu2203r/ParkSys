#include <stdio.h>

#define NUM_TEMPERATURAS 5 // Define uma constante para o número de temperaturas a serem lidas

// Função para encontrar a maior temperatura em um vetor de floats

float encontrarMaiorTemperatura(float temperaturas[], int tamanho);


int main() {
    float temperaturas[NUM_TEMPERATURAS];
    float maior; 

    printf("--- Leitura de Temperaturas ---\n");

    for (int i = 0; i < NUM_TEMPERATURAS; i++) {
        printf("Digite a temperatura %d: ", i + 1);
        scanf("%f", &temperaturas[i]); 
    }

    // Chama a função para encontrar a maior temperatura
    maior = encontrarMaiorTemperatura(temperaturas, NUM_TEMPERATURAS);

    printf("\n--- Resultados ---\n");
    printf("As temperaturas lidas foram: ");
    for (int i = 0; i < NUM_TEMPERATURAS; i++) {
        printf("%.2f ", temperaturas[i]); 
    }

    printf("A maior temperatura lida foi: %.2f graus Celsius.\n", maior); 

    return 0;
}

float encontrarMaiorTemperatura(float temperaturas[], int tamanho) {
    
    float maior_temperatura = temperaturas[0];

    
    for (int i = 1; i < tamanho; i++) {
        
        if (temperaturas[i] > maior_temperatura) {
            maior_temperatura = temperaturas[i];
        }
    }

    return maior_temperatura; 
}