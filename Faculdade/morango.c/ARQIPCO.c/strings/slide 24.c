#include <stdio.h>
#include <string.h> // Para strlen

int main() {
    char minhaString[20] = "Alo IFSP!"; // [cite: 215]
    char primeiraLetra;
    int i;

    primeiraLetra = minhaString[0]; // Pega 'A' (índice 0) [cite: 216, 217, 224]
    printf("1a letra: %c\n", primeiraLetra); // %c para char [cite: 217, 218, 225]

    printf("5a letra (indice 4): %c\n", minhaString[4]); // Pega 'I' [cite: 219]

    minhaString[0] = 'O'; // Muda 'A' para 'O' [cite: 220, 226]
    printf("Agora: %s\n", minhaString); // "Olo IFSP!" [cite: 220, 227]

    // Mostrando todas, uma por uma
    printf("Letras:\n");
    for (i = 0; minhaString[i] != '\0'; i++) { // Loop até o \0 [cite: 222, 227, 228, 229, 230, 231, 232]
        printf("Indice %d: %c\n", i, minhaString[i]); // [cite: 222, 223]
    }
    return 0;
}
