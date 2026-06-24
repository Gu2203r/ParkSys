#include <stdio.h>
#include <string.h> // Para strstr

int main() {
    char textoGrande[100] = "O IFSP de Araraquara eh legal!";
    char pedaco[20] = "Araraquara";
    char *pAchado; // "Dedo mágico" (ponteiro)

    pAchado = strstr(textoGrande, pedaco); // Procura

    if (pAchado != NULL) { // Achou se não for NULL
        printf("Achei '%s'!\n", pedaco);
        printf("Comeca em: %s\n", pAchado); // Mostra a partir do achado
        printf("No indice: %ld\n", pAchado - textoGrande); // Calcula o índice
    } else {
        printf("Nao achei '%s'.\n", pedaco); 
    }
    return 0;
}


