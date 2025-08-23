#include <stdio.h>
#include <string.h> // Para strncmp

int main() {
    char str1[20] = "abacaxi"; // [cite: 194]
    char str2[20] = "abacate";
    int resultado; // [cite: 195]

    // Compara os 4 primeiros chars ("abac" vs "abac") -> Iguais
    resultado = strncmp(str1, str2, 4); // [cite: 195, 206]
    if (resultado == 0) { printf("Primeiros 4 sao iguais.\n"); } // [cite: 196, 198, 207]

    // Compara os 6 primeiros chars ("abacax" vs "abacat") -> 'x' > 't'
    resultado = strncmp(str1, str2, 6); // [cite: 202, 208]
    if (resultado > 0) { printf("Nos 6 primeiros, '%s' vem depois.\n", str1); } // [cite: 205]
    return 0;
}


// strncmp é ótimo para verificar se uma string começa com um certo prefixo!
