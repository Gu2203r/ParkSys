#include <stdio.h>

int main() {
    float a[5] = {7.5, 6.5, 6.7, 8.5, 4.0};
    float soma = 0, media, limite;

    // Calcular a soma
    for (int i = 0; i < 5; i++) {
        soma += a[i];
    }

    // Calcular a média
    media = soma / 5;
    limite = media * 1.10;

    // Mostrar a média
    printf("Media: %.2f\n", media);

    // Mostrar os elementos 10% acima da média
    printf("Elementos acima de 10%% da media (%.2f):\n", limite);
    for (int i = 0; i < 5; i++) {
        if (a[i] > limite) {
            printf("%.2f ", a[i]);
        }
    }

    printf("\n");
    return 0;
}
