#include <stdio.h>
#include <string.h> // Para strcpy

int main() {
    char palavraOriginal[50] = "IFSP Araraquara"; // Original 
    char palavraCopia[50];   // Destino para a cópia

    // strcpy(destino, origem)
    strcpy(palavraCopia, palavraOriginal); // Copia 

    printf("Original: %s\n", palavraOriginal);
    printf("Copia: %s\n", palavraCopia); // Mostra a cópia
    return 0;
}


// CUIDADO! Se o destino for menor que a origem, strcpy pode "estourar a caixinha" (buffer overflow)!
