#include <stdio.h>
#include <string.h> // Para strncat

int main() {
    char fraseInicial[20] = "IFSP"; // Tem espaço (20). "IFSP" (4) + \0 (1). Sobram 15. 
    char paraAdicionar[30] = " Campus Araraquara Legal";

    // Adiciona no máx. 10 chars de paraAdicionar (" Campus Ar")
    strncat(fraseInicial, paraAdicionar, 10); 
    printf("Resultado: %s\n", fraseInicial); // "IFSP Campus Ar"

    char destinoPequeno[10] = "Ola"; // "Ola" (3) + \0 (1). Sobram 6.
    char origemGrande[20] = " Mundo Lindo"; 
    // Adiciona no máx. 3 chars (" Mu"). "Ola Mu" (6) + \0 (1) = 7. Cabe. 
    strncat(destinoPequeno, origemGrande, 3); 
    printf("Destino pequeno: %s\n", destinoPequeno); // "Ola Mu"
    return 0; // [cite: 181]
}


// Segurança: n é o limite de chars da origem. O destino ainda precisa ser grande o suficiente para a string original + os n chars + o \0 final.
