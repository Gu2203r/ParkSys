#include <stdio.h>  // Para printf, fgets, stdin
#include <string.h> // Para strcspn

int main() {
    char frase[100]; // "Caixinha" para a frase

    printf("Digite uma frase: ");
    // fgets(onde_guardar, tamanho_maximo_da_caixinha, de_onde_ler)
    fgets(frase, 100, stdin); // Lê a linha inteira

    // Remove o '\n' que o fgets pode deixar no final
    frase[strcspn(frase, "\n")] = '\0'; 

    printf("Voce digitou: %s\n", frase); // Mostra a frase lida

    return 0; // Indica que o programa terminou bem
}