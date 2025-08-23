#include <stdio.h>  // Para printf
#include <string.h> // Para strlen [cite: 19]

int main() {
    char minhaPalavra[50] = "Ola Mundo"; // Vetor de char
    int tamanho;

    tamanho = strlen(minhaPalavra); // Usa strlen

    // Mostra o resultado [cite: 17, 26]
    printf("A palavra '%s' tem %d letras.\n", minhaPalavra, tamanho);
    // %s para string, %d para inteiro 
    return 0; // Fim do programa
}


// #include <stdio.h>: Ferramentas de entrada/saída.
// #include <string.h>: Ferramentas para strings.
