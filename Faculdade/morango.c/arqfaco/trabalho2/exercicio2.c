#include <stdio.h>

int main() {
    float vetor[10];
    float valor;
    int achei = 0;

    // Lê os 10 números do vetor
    printf("Digite 10 numeros reais:\n");
    for (int i = 0; i < 10; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%f", &vetor[i]);
    }

    // Lê o valor a ser procurado
    printf("\nDigite o valor a procurar: ");
    scanf("%f", &valor);

    // Verifica se o valor está no vetor
    for (int i = 0; i < 10; i++) {
        if (vetor[i] == valor) {
            achei = 1;
            break;
        }
    }

    if (achei) {
        float limite = valor * 0.9;  // 10% menor que o valor
        printf("\nValores menores que %.2f (10%% menores que %.2f):\n", limite, valor);
        for (int i = 0; i < 10; i++) {
            if (vetor[i] < limite) {
                printf("%.2f ", vetor[i]);
            }
        }
        printf("\n");
    } else {
        printf("\nValor %.2f nao encontrado no vetor.\n", valor);
    }

    return 0;
}

