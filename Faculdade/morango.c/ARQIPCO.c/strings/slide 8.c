#include <stdio.h>
#include <string.h> // Para strcat

int main() {
    char primeiraParte[50] = "Ola"; // Precisa ter ESPAÇO EXTRA! 
    char segundaParte[20] = " Mundo"; // O que será adicionado

    // strcat(destino, origem)
    strcat(primeiraParte, segundaParte); // Junta as strings

    printf("Resultado: %s\n", primeiraParte); // Mostra "Ola Mundo"
    return 0;
}


// strcat encontra o \0 do destino, remove-o, copia a origem, e adiciona o \0 da origem.
// CUIDADO! Se o destino não tiver espaço suficiente para a string adicionada, strcat também pode "estourar a caixinha"!
